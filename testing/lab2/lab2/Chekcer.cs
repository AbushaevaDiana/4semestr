using HtmlAgilityPack;


namespace CheckerLinks
{
    //наследуем от сборщика мусора
    class Checker : IDisposable
    {
        private readonly List<string> validLinks = new List<string>();
        private readonly List<string> invalidLinks = new List<string>();
        private readonly List<string> allLinks = new List<string>();
        private static string inputLink = "";

        (int, int) validCodesBorders = (200, 400);

        private readonly HttpClient client = new HttpClient();

        public Checker(string link)
        {
            inputLink = link;
        }

        //освобождение ресурсов
        public void Dispose()
        {
            client.Dispose();
        }
        private bool IsValidLink(HttpResponseMessage clientResponse)
        {
            int statusCode = (int)clientResponse.StatusCode;

            if (statusCode < validCodesBorders.Item2 && statusCode >= validCodesBorders.Item1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        public void CheckAllLinks()
        {
            allLinks.Add(inputLink);
            char[] arr = inputLink.ToCharArray();
            int i = arr.Length;
            GetLinks(inputLink);

            foreach (var address in allLinks)
            {
                string url;
                if (!address.StartsWith("http://") && !address.StartsWith("https://"))
                {
                    url = inputLink + address;
                }
                else
                {
                    url = address;
                }

                var clientResponse = client.GetAsync(url).Result;
                int code = (int)clientResponse.StatusCode;
                string response = $"{url} {code} {clientResponse.StatusCode}";

                if (IsValidLink(clientResponse))
                {
                    validLinks.Add(response);
                }
                else
                {
                    invalidLinks.Add(response);
                }
            }
        }

        private void GetLinks(string link)
        {
            try
            {
                HtmlWeb htmlWeb = new HtmlWeb();
                HtmlDocument htmlDocument = htmlWeb.Load(link);
                HtmlNode[] htmlNodes = htmlDocument.DocumentNode.SelectNodes("//a").ToArray();

                foreach (HtmlNode node in htmlNodes)
                {
                    string url = node.GetAttributeValue("href", null);

                    if (((url != "") && (url != "/") && (url != "#")) && Uri.IsWellFormedUriString(url, UriKind.RelativeOrAbsolute))
                    {
                        if (url.Contains(inputLink) || (!url.StartsWith("http://") && !url.StartsWith("https://") && !url.StartsWith("//") && !url.Contains(':')))
                        {
                            if (!allLinks.Contains(url))
                            {
                                allLinks.Add(url);

                                if (url.Contains(inputLink))
                                {
                                    GetLinks(url);
                                }
                                else
                                {
                                    GetLinks(inputLink + url);
                                }
                            }
                        }
                    }
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }

        public List<string> GetValidLinks()
        {
            return validLinks;
        }

        public List<string> GetInvalidLinks()
        {
            return invalidLinks;
        }
    }
}
