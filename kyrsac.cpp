#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <cstdlib>
#include <map>


using namespace std;

int N;

struct Fio {
    string family, name, otchestvo;

    void set_fio(string s) {
        string word = "";
        string all_words[3];
        s += " ";
        for (auto c : s) {
            if (c == ' ') {
                if (word != "") {
                    all_words.push_back(word);
                    word = "";
                }
            }
            else {
                word += c;
            }
        }
        if ((int)all_words.size() >= 1) {
            family = all_words[0];
        }
        if ((int)all_words.size() >= 2) {
            name = all_words[1];
        }
        if ((int)all_words.size() >= 3) {
            otchestvo = all_words[2];
        }
    }

    string get() {
        string ans = "";
        ans += family;
        ans += " ";
        ans += name;
        ans += " ";
        ans += otchestvo;
        return ans;
    }

    void print() {
        cout << get() << '\n';
    }
};

struct Birth {
    int day, month, year;

    void set_birth(string s) {
        day = (s[0] - '0') * 10 + s[1] - '0';
        month = (s[3] - '0') * 10 + s[4] - '0';
        year = (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] - '0') * 10 + s[9] - '0';
    }

    void print() {
        cout << day << "." << month << "." << year << '\n';
    }
};

struct People {
    Fio fio;
    Birth birth;
    int year;
    string faculty;
    string group;
    int number;
    string gender;
    vector < pair < string, int > > mark;
};

bool operator< (People a, People b) {
    return a.fio.get() < b.fio.get();
}

void print(vector < People > a) {
    sort(a.begin(), a.end());
    for (auto key : a) {
        key.fio.print();
        key.birth.print();
        cout << key.year << '\n';
        cout << key.faculty << '\n';
        cout << key.group << '\n';
        cout << key.number << '\n';
        cout << key.gender << '\n';
        cout << key.mark.size() << '\n';
        for (auto element : key.mark) {
            cout << element.first << " " << element.second << '\n';
        }
    }
}

int main() {
    #pragma warning(suppress : 4996)
    freopen("input.txt", "r", stdin);
    #pragma warning(suppress : 4996)
    freopen("output.txt", "w", stdout);
    int N;
    cin >> N;
    string s;
    getline(cin, s);
    vector < People > all_people;
    for (int i = 1; i <= N; ++i) {
        People now;
        getline(cin, s);
        now.fio.set_fio(s);
        getline(cin, s);
        now.birth.set_birth(s);
        cin >> now.year;
        getline(cin, s);
        getline(cin, now.faculty);
        cin >> now.group;
        cin >> now.number;
        cin >> now.gender;
        int cnt;
        cin >> cnt;
        for (int j = 1; j <= cnt; ++j) {
            now.mark.emplace_back();
            cin >> now.mark.back().first >> now.mark.back().second;
            getline(cin, s);
        }
        if (cnt == 0) {
            getline(cin, s);
        }
        all_people.push_back(now);
    }

    string gender;
    int year;
    cin >> gender >> year;
    vector < People > set1, set2;
    for (auto key : all_people) {
        if (key.gender != gender) {
            continue;
        }
        if (key.year == year) {
            set1.push_back(key);
        }
        else {
            set2.push_back(key);
        }
    }

    print(set1);
    cout << "--------------------------------" << '\n';
    print(set2);

    return 0;
}
