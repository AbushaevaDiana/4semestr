using System;
using System.Diagnostics;
using System.IO;

namespace Tests
{
    class Program
    {
        static string Test(string program, string args)
        {
            try
            {
                using Process process = new();
                process.StartInfo.UseShellExecute = false;
                process.StartInfo.RedirectStandardOutput = true;
                process.StartInfo.FileName = program;
                process.StartInfo.Arguments = args;
                process.StartInfo.CreateNoWindow = true;
                process.Start();

                string output = process.StandardOutput.ReadToEnd();
                return output;
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                return "programm error";
            }

        }

        static bool IsFilesExists(string programFile, string testsFile)
        {
            if (!File.Exists(programFile))
            {
                Console.WriteLine("Triangle program not found!");
                return false;
            }

            if (!File.Exists(testsFile))
            {
                Console.WriteLine("Tests not found!");
                return false;
            }

             return true;
        }
        static void Main()
        {
            string programFile = "../../../../../lab1/lab1/bin/Debug/net6.0/lab1.exe";
            string testsFile = "../../../../tests.txt";

            if (!IsFilesExists(programFile, testsFile))
            {
                return;
            }

            string outputFile = "../../../../testOutput.txt";
           

            using (StreamWriter output = new(outputFile))
            {
                foreach (string line in File.ReadLines(testsFile))
                {
                    if (line != "")
                    {
                        string[] t = line.Split('~');
                        string triangleArgs = t[0];
                        string testResult = t[1];

                        string result = Test(programFile, triangleArgs);
                        string test = "success";
                        if (testResult != result)
                        {
                            test = "error";
                        }
                        output.WriteLine(test);
                    }
                    else 
                    {
                        output.WriteLine();
                    }
                }
            }

            Console.WriteLine("Проверка тестов закончена!");
        }
    }
}