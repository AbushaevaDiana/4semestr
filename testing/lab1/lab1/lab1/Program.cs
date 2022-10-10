using System;

namespace Triangle
{
    class Program
    {
        static string GetTriangleType(double a, double b, double c)
        {
            if (!((a + b > c) && (a + c > b) && (b + c > a)))
            {
                return "Не треугольник";
            }

            if ((a == b) && (b == c))
            {
                return "Равносторонний";
            }

            if ((a == b) || (a == c) || (b == c))
            {
                return "Равнобедренный";
            }

            return "Обычный";
        }

        static void Main(string[] args)
        {
            if (args.Length != 3)
            {
                Console.Write("Неизвестная ошибка!");
                return;
            }

            try
            {
                    double a = Convert.ToDouble(args[0]);
                    double b = Convert.ToDouble(args[1]);
                    double c = Convert.ToDouble(args[2]);
                    Console.Write(GetTriangleType(a, b, c)); 
            }
            catch (Exception)
            {
                Console.Write("Неизвестная ошибка!");
            }
        }

    }
}