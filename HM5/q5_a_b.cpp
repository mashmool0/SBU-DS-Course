#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// الف) ساختار گره‌ها
class TrieNode
{
public:
    unordered_map<char, TrieNode *> children; // نگهداری فرزندان با map
    bool isEndOfWord;                         // نشانگر پایان کلمه
    string meaning;                           // معنی کلمه (در صورت پایان کلمه بودن)

    TrieNode()
    {
        isEndOfWord = false;
    }
};

// کلاس اصلی فرهنگ لغت
class Dictionary
{
private:
    TrieNode *root;

public:
    Dictionary()
    {
        root = new TrieNode();
    }

    // ب) تابع درج کلمه جدید
    void insert(string word, string meaning)
    {
        TrieNode *current = root;

        for (char ch : word)
        {
            // اگر حرف موجود نبود، گره جدید ایجاد می‌کنیم
            if (current->children.find(ch) == current->children.end())
            {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }

        // ثبت پایان کلمه و معنی آن
        current->isEndOfWord = true;
        current->meaning = meaning;
    }

    // ب) تابع جستجوی کلمه
    bool search(string word, string &meaning)
    {
        TrieNode *current = root;

        for (char ch : word)
        {
            // اگر حرفی پیدا نشد، کلمه وجود ندارد
            if (current->children.find(ch) == current->children.end())
            {
                return false;
            }
            current = current->children[ch];
        }

        // اگر به پایان کلمه رسیدیم، معنی را برمی‌گردانیم
        if (current->isEndOfWord)
        {
            meaning = current->meaning;
            return true;
        }
        return false;
    }

    // ب) تابع حذف کلمه
    bool remove(string word)
    {
        return removeHelper(root, word, 0);
    }

private:
    bool removeHelper(TrieNode *node, string &word, int depth)
    {
        if (!node)
            return false;

        // به انتهای کلمه رسیدیم
        if (depth == word.length())
        {
            if (!node->isEndOfWord)
                return false;

            node->isEndOfWord = false;
            node->meaning = "";

            // اگر گره فرزندی ندارد، می‌تواند حذف شود
            return node->children.empty();
        }

        char ch = word[depth];
        if (node->children.find(ch) == node->children.end())
        {
            return false;
        }

        bool shouldDeleteChild = removeHelper(node->children[ch], word, depth + 1);

        // اگر فرزند باید حذف شود
        if (shouldDeleteChild)
        {
            delete node->children[ch];
            node->children.erase(ch);

            // اگر این گره پایان کلمه نیست و فرزندی ندارد
            return !node->isEndOfWord && node->children.empty();
        }

        return false;
    }
};

// مثال استفاده
int main()
{
    Dictionary dict;

    // درج چند کلمه
    dict.insert("سلام", "واژه‌ای برای احوالپرسی");
    dict.insert("کتاب", "مجموعه‌ای از نوشته‌ها");
    dict.insert("برنامه", "طرح از پیش تعیین شده");

    // جستجوی کلمه
    string meaning;
    if (dict.search("سلام", meaning))
    {
        cout << "معنی کلمه: " << meaning << endl;
    }
    else
    {
        cout << "کلمه یافت نشد!" << endl;
    }

    // حذف کلمه
    if (dict.remove("کتاب"))
    {
        cout << "کلمه با موفقیت حذف شد" << endl;
    }

    return 0;
}