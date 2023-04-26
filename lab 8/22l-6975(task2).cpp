#include <iostream>
using namespace std;
class Author
{
    string name;
    string email;
    char gender;

public:
    Author();
    void operator=(const Author &);
    Author(const Author &);
    Author(const string &, const string &, char);
    string getName() const;
    string getEmail() const;
    void setEmail(const string &);
    char getGender() const;
    void print() const;
};

class Book
{
    string name;
    Author author;
    double price;
    int qtyInStock = 0;

public:
    Book(const string &,const Author&, double, int);
    string getName() const;
    Author getAuthor() const;
    double getPrice() const;
    void setprice(double);
    int getQtyInstock() const;
    void setQtyInstock(int);
    void print();
    string getAuthorName() const;
};
int main()
{
    Author peter("Peter Jones", "peter@somewhere.com", 'm');
    peter.print();
    Book book("C++ for Dummies",peter,19.99,1);
    cout<<endl;
    book.print();
    peter.setEmail("peter@xyz.com");
    cout<<endl;
    peter.print();
    cout<<endl;
    book.print();
    book.getAuthor().setEmail("peter@abc.com");
    cout<<endl;
    book.print();
    cout << "\n\n";
    system("pause");
    return 0;
}

Author::Author(){
    name = "/0";
    email = "/0";
    gender = 'n';
}

Author::Author(const Author &obj)
{
    name = obj.name;
    email = obj.email;
    gender = obj.gender;
}

void Author::operator=(const Author &obj)
{
    name = obj.name;
    email = obj.email;
    gender = obj.gender;
}

Author::Author(const string &na, const string &em, char ge)
{
    name = na;
    email = em;
    gender = ge;
}

string Author::getEmail() const
{
    return email;
}

string Author::getName() const
{
    return name;
}

void Author::setEmail(const string &em)
{
    email = em;
}

char Author::getGender() const
{
    return gender;
}

void Author::print() const
{
    cout << name << " (" << gender << ") at " << email;
}

Book::Book(const string &n,const Author& A, double p, int Q)
{
    name = n;
    author = A;
    price = p;
    qtyInStock = Q;
}

string Book::getName() const
{
    return name;
}

Author Book::getAuthor() const
{
    return author;
}

double Book::getPrice() const{
    return price;
}

void Book::setprice(double a){
    price = a;
}

int Book::getQtyInstock() const{
    return qtyInStock;
}

void Book::setQtyInstock(int a){
    qtyInStock = a;
}

void Book::print(){
    cout<<name<<" by "<<author.getName()<<" ("<<author.getGender()<<") at "<<author.getEmail();
}

string Book::getAuthorName() const{
    return author.getName();
}