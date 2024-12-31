#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std; // namespace std ���

class Book {
public:
    string title;
    string author;

    Book(const string& title, const string& author)
        : title(title), author(author) {
    }
    // book�� �̸��� ���ڷ� ���ϴ� �ż��� �߰� : �˻� ��� �߰��� ����
     // �̸� �� �޼���
    bool hasTitle(const string& otherTitle) const {
        return title == otherTitle;
    }

    // ���� �� �޼���
    bool hasAuthor(const string& otherAuthor) const {
        return author == otherAuthor;
    }
};

class BookManager {
private:
    vector<Book> books; // å ��� ����
    vector<Book> search; // �˻��� ����
public:
    // å �߰� �޼���
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // push_back ���
        cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
    }

    // ��� å ��� �޼���
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }

        cout << "���� ���� ���:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }
    // å �̸����� å �˻� �ϴ� �޼ҵ�
    void searchByTitle(string title) const {
        auto it = find_if(books.begin(), books.end(),
            [&title](const Book& book) { return book.hasTitle(title); });
        if (it != books.end()) {
            cout << "�ش� å�� �̸�: " << it->title << ", ����: " << it->author << endl;
        }
        else {
            cout << "�ش� �Ǵ� å �̸��� �����ϴ�." << endl;
        }
    }
    // ���� �̸����� å �˻� �ϴ� �޼ҵ�
    void searchByAuthor(string author) const {
        auto it = find_if(books.begin(), books.end(),
            [&author](const Book& book) { return book.hasAuthor(author); });
        if (it != books.end()) {
            cout << "�ش� å�� �̸�: " << it->title << ", ����: " << it->author << endl;
        }
        else {
            cout << "�ش� �Ǵ� ���� �̸��� �����ϴ�." << endl;
        }
    }
};

int main() {
    BookManager manager;

    // ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
    // ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
    while (true) {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl; // å ������ �Է¹޾� å ��Ͽ� �߰�
        cout << "2. ��� å ���" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
        cout << "3. å ������ ���� �˻�" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
        cout << "4. å ���ڸ� ���� �˻�" << endl; // ���� å ��Ͽ� �ִ� ��� å ���
        cout << "5. ����" << endl; // ���α׷� ����
        cout << "����: ";

        int choice; // ������� �޴� ������ ����
        cin >> choice;

        if (choice == 1) {
            // 1�� ����: å �߰�
            // ����ڷκ��� å ����� ���ڸ��� �Է¹޾� BookManager�� �߰��մϴ�.
            string title, author;
            cout << "å ����: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, title); // ���� �Է� (���� ����)
            cout << "å ����: ";
            getline(cin, author); // ���ڸ� �Է� (���� ����)
            manager.addBook(title, author); // �Է¹��� å ������ �߰�
        }
        else if (choice == 2) {
            // 2�� ����: ��� å ���
            // ���� BookManager�� ����� å ����� ����մϴ�.
            manager.displayAllBooks();
        }
        else if (choice == 3) {
            // 3�� ����: ������ ���� �˻�
            // ���� BookManager�� ����� å ����� ����մϴ�.
            string title;
            cout << "å ����: ";
            cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(cin, title); // ���� �Է� (���� ����)
            manager.searchByTitle(title);
        }
        else if (choice == 4) {
            // 2�� ����: ��� å ���
            // ���� BookManager�� ����� å ����� ����մϴ�.
            string author;
            cout << "å ����: ";
            cin.ignore();
            getline(cin, author); // ���ڸ� �Է� (���� ����)
            manager.searchByAuthor(author);
        }
        else if (choice == 5) {
            // 3�� ����: ����
            // ���α׷��� �����ϰ� ����ڿ��� �޽����� ����մϴ�.
            cout << "���α׷��� �����մϴ�." << endl;
            break; // while ���� ����
        }
        else {
            // �߸��� �Է� ó��
            // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0; // ���α׷� ���� ����
}
