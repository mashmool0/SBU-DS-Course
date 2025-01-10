#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ساختار گره درخت Trie
class TrieNode
{
public:
    bool isEndOfWord;            // نشان‌دهنده پایان کلمه
    vector<TrieNode *> children; // فرزندان گره
    char data;                   // داده هر گره

    TrieNode(char c)
    {
        data = c;
        isEndOfWord = false;
        children = vector<TrieNode *>(26, nullptr);
    }
};

class Trie
{
private:
    TrieNode *root;

    // تابع بازگشتی برای چاپ همه کلمات با پیشوند مشخص
    void printWordsWithPrefix(TrieNode *node, string prefix)
    {
        if (node->isEndOfWord)
        {
            cout << prefix << endl;
        }

        for (int i = 0; i < 26; i++)
        {
            if (node->children[i] != nullptr)
            {
                printWordsWithPrefix(node->children[i], prefix + (char)(i + 'a'));
            }
        }
    }

public:
    Trie()
    {
        root = new TrieNode('\0'); // ریشه با کاراکتر خالی
    }

    // درج کلمه در درخت
    void insert(string word)
    {
        TrieNode *current = root;

        for (char c : word)
        {
            int index = c - 'a';
            if (current->children[index] == nullptr)
            {
                current->children[index] = new TrieNode(c);
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }

    // جستجوی پیشوند و چاپ همه کلمات با آن پیشوند
    void searchPrefix(string prefix)
    {
        TrieNode *current = root;

        // پیدا کردن گره پایانی پیشوند
        for (char c : prefix)
        {
            int index = c - 'a';
            if (current->children[index] == nullptr)
            {
                cout << "هیچ کلمه‌ای با این پیشوند یافت نشد!" << endl;
                return;
            }
            current = current->children[index];
        }

        // چاپ همه کلمات با این پیشوند
        cout << "کلمات با پیشوند " << prefix << ":" << endl;
        printWordsWithPrefix(current, prefix);
    }
};

int main()
{
    Trie tree;

    // اضافه کردن چند کلمه به درخت
    tree.insert("tree");
    tree.insert("trie");
    tree.insert("try");
    tree.insert("triangle");
    tree.insert("trap");

    // جستجوی کلمات با پیشوند "tr"
    tree.searchPrefix("tr");

    return 0;
}