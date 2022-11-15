using Xunit;

namespace NewProject.tests;

public class BookTests
{
    [Fact]
    public void BookCalculateAverageGrades()
    {
        // arrange
        var book = new InMemoryBook("");
        book.AddGrade(99.1);
        book.AddGrade(25.1);
        book.AddGrade(11.2);

        // act
        var result = book.GetStatistic();
        
        // assert
        Assert.Equal(45.1, result.Average, 1);
        Assert.Equal(99.1, result.High, 1);
        Assert.Equal(11.2, result.Low, 1);

    }
}