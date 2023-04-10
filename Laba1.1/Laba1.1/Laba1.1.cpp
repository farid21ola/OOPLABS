#include <iostream>
#include <vector>
#include <string>

enum class Genre {
    Art, Tech, None
};

class Book {
public:
    Book(const std::string& auth, const std::string& nam, const Genre& gen) : author(auth), name(nam), genre(gen) {
    }
    Genre gen()const {
        return this->genre;
    }
    bool validation()const {
        return !author.empty() && !name.empty();
    }
private:
    const std::string name, author;
    const Genre genre;
};

class Library {
public:
    std::vector<Book*> v;

    void AddBook(const std::string& auth, const std::string& nam, const Genre& gen) {
        if (!auth.empty() && !nam.empty()) {
            v.push_back(new Book(auth, nam, gen));
        }
        else {
            std::cout << "Incorrect book title or author's name" << std::endl;
        }
    }
    ~Library() {
        for (auto book : v) {
            delete book;
        }
    }

};

void Count(const Library& v) {
    int a = 0,
        t = 0;
    for (auto book : v.v) {
        switch (book->gen())
        {
        case Genre::Art:
            ++a;
            break;
        case Genre::Tech:
            ++t;
            break;
        }
    }
    std::cout << a << "\n" << t << "\n";
}

void withoutSwCount(Library& v) {
    int a = 0,
        t = 0;
    for (auto book : v.v) {

        if (book->gen() == Genre::Art) {
            ++a;
        }
        else {
            ++t;
        }
    }
    std::cout << a << "\n" << t << "\n";
}

int main()
{
    std::vector<Book*> v;
    Library lib;
    lib.AddBook("Пушкин", "Колобок", Genre::Art);
    lib.AddBook("Пушкин", "BABABok", Genre::Art);
    lib.AddBook("", "", Genre::Art);
    Count(lib);
    withoutSwCount(lib);
    return 0;
}