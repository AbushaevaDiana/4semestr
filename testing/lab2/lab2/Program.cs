using System;
using HtmlAgilityPack;
using System.Collections.Generic;
using System.IO;
using System.Net;

namespace Links
{
    class Program
    {
        static Dictionary<string, HttpStatusCode> links = new Dictionary<string, HttpStatusCode>();

        static void Main()
        {
            string StartUrl = "http://links.qatl.ru/";
            string protocol = "http://";
            string domen = "links.qatl.ru";

            CheckLink(StartUrl, domen, protocol);
            Output();
            Console.WriteLine("Check success");
        }

        static void Output()
        {

            string brokenFile = "../../../../brokenFile.txt";
            string validFile = "../../../../validFile.txt";
            if (!File.Exists(brokenFile))
            {
                Console.WriteLine("Broken file not found!");
                return;
            }
            if (!File.Exists(validFile))
            {
                Console.WriteLine("Valid file not found!");
                return;
            }

            using StreamWriter broken = new StreamWriter(brokenFile, false, System.Text.Encoding.Default);
            using StreamWriter valid = new StreamWriter(validFile, false, System.Text.Encoding.Default);

            int brokenLinksCount = 0;
            int validLinksCount = 0;
            foreach (KeyValuePair<string, HttpStatusCode> link in links)
            {
                if ((int)link.Value >= 200 && (int)link.Value < 400)
                {
                    valid.WriteLine(link.Key + " - " + (int)link.Value);
                    validLinksCount++;
                }
                else
                {
                    broken.WriteLine(link.Key + " - " + (int)link.Value);
                    brokenLinksCount++;
                }
            }
            string date = DateTime.Today.ToString("d");

            broken.WriteLine("Number of brokenFile links: " + brokenLinksCount);
            broken.WriteLine(date);

            valid.WriteLine("Number of no brokenFile links: " + validLinksCount);
            valid.WriteLine(date);
        }

        static void CheckLink(string url, string domen, string protocol)
        {
            Answer answer;
            try
            {
                Console.WriteLine("Check: " + url);
                answer = MakeRequest(url);
            }
            catch (Exception)
            {
                links.Add(url, HttpStatusCode.GatewayTimeout);
                return;
            }
            links.Add(answer.link, answer.status);
            List<string> newLinks = HtmlAgilityPack(answer.html);

            for (int i = 0; i < newLinks.Count; i++)
            {
                try
                {
                    string link = protocol + domen + newLinks[i];
                    Uri uri = new Uri(link);
                    if (uri.Host == domen)
                    {
                        CheckLink(link, domen, protocol);
                    }
                }
                catch (Exception)
                {
                }
            }
        }

        static readonly HttpClient client = new HttpClient();
        static Answer MakeRequest(string url)
        {
            try
            {
                using HttpResponseMessage response = await client.GetAsync("todos/3");

                response.EnsureSuccessStatusCode()
                    .WriteRequestToConsole();

                var jsonResponse = await response.Content.ReadAsStringAsync();
                WriteLine($"{jsonResponse}\n");

                HttpWebResponse response = (HttpWebResponse)request.GetResponse();

                //HttpResponseMessage response = client.GetAsync(url);
                //response.EnsureSuccessStatusCode();
                string responseBody = await response.Content.ReadAsStringAsync();



                HttpWebRequest request = (HttpWebRequest)HttpClient.Create(url);
                
                //Stream stream = response.GetResponseStream();
                StreamReader sr = new StreamReader(stream);

                string html = sr.ReadToEnd();
                HttpStatusCode status = response.StatusCode;
                response.Close();

                return new Answer(html, url, status);
            }
            catch (WebException e)
            {
                return new Answer("", url, ((HttpWebResponse)e.Response).StatusCode);
            }
        }

        static List<string> HtmlAgilityPack(string html)
        {
            HtmlDocument htmlSnippet = new HtmlDocument();
            htmlSnippet.LoadHtml(html);

            List<string> Links = new List<string>();
            string[] attributes = { "href", "icon", "manifest", "poster", "src", "cite", "action" };
            foreach (HtmlAttribute att in htmlSnippet.DocumentNode.GetAttributes(attributes))
            {
                Links.Add(att.Value);
            }

            return Links;
        }
        public struct Answer
        {
            public Answer(string html, string link, HttpStatusCode status)
            {
                this.html = html;
                this.link = link;
                this.status = status;
            }

            public string html;
            public string link;
            public HttpStatusCode status;
        }
    }
}