namespace NewProject
{
    public delegate void GradeAddedDelegate(object sender, EventArgs args);

    public abstract class Book : NamedObject, IBook
    {
        public Book(string name) : base(name)
        {
        }

        public abstract event GradeAddedDelegate GradeAdded;

        public abstract void AddGrade(double Grade);

        public abstract Statistic GetStatistic();

    }

    public interface IBook
    {
        void AddGrade(double grade);
        Statistic GetStatistic();
        string Name { get; }
        event GradeAddedDelegate GradeAdded;
    }

    public class DiskBook : Book 
    {
        public DiskBook(string name) : base(name)
        {
        }

        public override event GradeAddedDelegate GradeAdded;

        public override void AddGrade(double Grade)
        {
            File.AppendText("Andy's gradebook.txt", );
        }

        public override Statistic GetStatistic()
        {
            throw new NotImplementedException();
        }
    }

    public class InMemoryBook : Book
    {
        private List<double>grades; 

        public List<double> Grades
        {
            get
            {
                return grades;
            }
        }

        public InMemoryBook(string name) : base(name)
        {

            grades = new List<double>();
            Name = name;
        }
        public override void AddGrade(double grade)
        {
            if (grade >= 0 && grade <= 100)
            {
                grades.Add(grade);
                if (GradeAdded != null)
                {
                    GradeAdded(this, new EventArgs());
                }
            }
            else
            {
                throw new ArgumentException($"Invalid {nameof(grade)}");
            }
        }

        public override event GradeAddedDelegate GradeAdded = delegate { };

        public void ShowGrade()
        {
            foreach(var number in grades)
                Console.WriteLine(number);
        }

        public override Statistic GetStatistic()
        {
            var result = new Statistic();
            result.Average = 0.0;
            result.High = double.MinValue;
            result.Low = double.MaxValue;
            foreach (var i in grades)
            {
                result.High = Math.Max(i, result.High);
                result.Low = Math.Min(i, result.Low);
                result.Average += i;
            }

            result.Average /= grades.Count;
            return result;
        }
    }
}