using System;

namespace NewProject
{
    class Program
    {
        static void Main(string[] args)
        {
            IBook book = new DiskBook("Andy's gradebook");
            book.GradeAdded += OnGradeAdded;

            EnterGrade(book);

            var stats = book.GetStatistic();
            System.Console.WriteLine($"The highest grade is: {stats.High}");
            System.Console.WriteLine($"The lowest grade is: {stats.Low}");
            System.Console.WriteLine($"The result is: {stats.Average}");
        }

        private static void EnterGrade(IBook book)
        {
            var done = false;
            Console.Write("Please enter a grade: ");
            do
            {
                var input = Console.ReadLine();
                if (input == "q")
                    done = true;
                else
                {
                    try
                    {
                        if (input != null)
                        {
                            var grade = double.Parse(input);
                            book.AddGrade(grade);
                        }
                    }
                    catch (ArgumentException ex)
                    {
                        System.Console.WriteLine(ex.Message);
                    }
                    catch (FormatException ex)
                    {
                        System.Console.WriteLine(ex.Message);
                    }
                    finally
                    {
                        Console.WriteLine("****");
                    }
                }
            } while (!done);
        }

        static void OnGradeAdded(object sender, EventArgs e)
        {
            System.Console.WriteLine("A grade was added");
        }
    }
}