using CheckerLinks;

namespace Program 
{ 
    class Program
    {
        static void PrintLinksToFile(StreamWriter stream, List<string> links)
        {
            foreach (var link in links)
            {
                stream.WriteLine(link);
            }

            stream.WriteLine("количество ссылок: " + links.Count());
            stream.WriteLine("дата проверки: " + DateTime.Now);
        }
        static void Main(string[] args)
        {
            try
            {
                if (args.Length != 1)
                {
                    throw new Exception("неверное количество входных аргументов");
                }
                string link = args[0];

                using (Checker checker = new Checker(link))
                {
                    checker.CheckAllLinks();

                    string validFile = "valid.txt";
                    string invalidFile = "invalid.txt";
                    StreamWriter validStreamWriter = new(validFile);
                    StreamWriter invalidStreamWriter = new(invalidFile);
                    PrintLinksToFile(validStreamWriter, checker.GetValidLinks());
                    PrintLinksToFile(invalidStreamWriter, checker.GetInvalidLinks());

                    validStreamWriter.Close();
                    invalidStreamWriter.Close();
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }
    }
}