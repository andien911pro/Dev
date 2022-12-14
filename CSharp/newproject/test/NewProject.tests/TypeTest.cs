using System;
using Xunit;

namespace NewProject.tests;

public delegate string WriteLogDelegate(string logMessage);

public class TypeTest
{ 
    int count = 0;

    [Fact]
    public void WriteLogDelegateCanPointToMethod()
    {
        WriteLogDelegate log = returnMessage;
        
        log += incrementCount;
        log += returnMessage;
        
        var result = log("Hello");
        Assert.Equal(3, count);
        Assert.Equal("hello", result);
    }

    string incrementCount(string message)
    {
        ++count;
        return message.ToLower();
    }

    string returnMessage(string message)
    {
        ++count;
        return message;
    }

    [Fact]
    public void StringBehavesLikeValueType()
    {
        string name = "Andy";
        var upper = MakeUppercase(name);

        Assert.Equal("Andy", name);
        Assert.Equal("ANDY", upper);
    }

    private string MakeUppercase(string parameter)
    {
        return parameter.ToUpper();
    }

    [Fact]
    public void Test1()
    {
        var x = GetInt();
        SetInt(ref x);

        Assert.Equal(42, x);
    }

    private void SetInt(ref int x)
    {
        x = 42;
    }

    private int GetInt()
    {
        return 3;
    }
    [Fact]
    public void CSharpCanPassByReference()
    {
        var book1 = GetBook("Book 1");
        GetBookSetName(ref book1, "New name");
        
        Assert.Equal("New name", book1.Name);
    }

    private void GetBookSetName(ref InMemoryBook book, string name)
    {
        book = new InMemoryBook(name);
    }

   [Fact]
    public void CSharpIsPassByValue()
    {
        var book1 = GetBook("New name");
        GetBookSetName(book1, "New name");
        
        Assert.Equal("New name", book1.Name);
    }

    private void GetBookSetName(InMemoryBook book, string name)
    {
        book = new InMemoryBook(name);
    }

    [Fact]
    public void CanSetNameFromReference()
    {
        var book1 = GetBook("Book 1");
        SetName(book1, "New name");
        
        Assert.Equal("New name", book1.Name);
    }

    private void SetName(InMemoryBook book, string name)
    {
        book.Name = name;
    }

    [Fact]
    public void GetBookReturnsDifferentObjects()
    {
        var book1 = GetBook("Book 1");
        var book2 = GetBook("Book 2");

        Assert.Equal("Book 1", book1.Name);
        Assert.Equal("Book 2", book2.Name);
        Assert.NotSame(book1, book2);
    }
    
    [Fact]
    public void TwoVarsCanReferencesSameObject()
    {
        var book1 = GetBook("Book 1");
        var book2 = book1;

        Assert.Same(book1, book2);
        Assert.True(Object.ReferenceEquals(book1, book2));
    }
    private InMemoryBook GetBook(string name)
    {
        return new InMemoryBook(name);
    }
}