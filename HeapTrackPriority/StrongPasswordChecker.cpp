#include <bits/stdc++.h>
using namespace std;


int strongPasswordChecker0(string password) {
    int size = password.length();
    int l,u,d;
    l=u=d=0;

    if(size <= 20)
    {
        int can_rep = 0;
        int must_repl = 0;
        int tm, j;
        for (int i = 0; i < size;) {
            if(!u && isupper(password[i]))
                u = 1;
            else if(!l && islower(password[i]))
                l = 1;
            else if(!d && isdigit(password[i]))
                d = 1;

            j = i+1;

            while(j < size && password[i]==password[j])
                j++;

            tm = j - i;
            can_rep += tm/3;
            i=j;
        }

        if(!l) must_repl+=1;
        if(!u) must_repl+=1;
        if(!d) must_repl+=1;

        return max(((6-size)<0 ? 0:6-size),max(can_rep,must_repl));

    }
    else
    {

        int min_del=size-20,must_repl=0;
        int crr_len=0;
        priority_queue<int>pq;
        int tm, j;
        for(int i=0;i<size;)
        {
            if(!u && isupper(password[i]))
                u = 1;
            else if(!l && islower(password[i]))
                l = 1;
            else if(!d && isdigit(password[i]))
                d = 1;

            j = i+1;

            while(j < size && password[i]==password[j])
                j++;


            tm = j - i;

            if(tm>=2)
            {
                crr_len+=2;
                pq.push(tm-2);
            }
            else
                crr_len+=1;

            i=j;
        }

        if(!l) must_repl+=1;
        if(!u) must_repl+=1;
        if(!d) must_repl+=1;

        if(crr_len>=20)
            return min_del+must_repl;
        else
        {
            int min_replacement=0;
            while(crr_len<20)
            {
                int x=pq.top();
                crr_len+=min(3,x);
                x-=max(3,x);
                min_replacement+=1;
            }

            return min_del+max(min_replacement,must_repl);
        }

    }

    return 0;
}

int strongPasswordChecker(string s) {

    // For diversity requirement.
    bool lower_case(false), upper_case(false), digit(false);

    // For repeats.
    std::vector<int> run_lengths;

    char curr;
    int run_length(0);
    for (int i = 0; i < s.size(); ++i) {
        // Do we need new characters.
        if (s[i] >= 'a' && s[i] <= 'z') {
            lower_case = true;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            upper_case = true;
        } else if (s[i] > '0' && s[i] <= '9') {
            digit = true;
        }

        // Repeats.
        if (i == 0) {
            curr = s[0];
            run_length = 1;
            continue;
        }
        if (s[i] == curr) {
            ++run_length;
        } else {
            if (run_length >= 3) {
                run_lengths.push_back(run_length);
            }
            curr = s[i];
            run_length = 1;
        }
    }
    if (run_length >= 3) {
        run_lengths.push_back(run_length);
    }


    // Number of new characters needed.
    int num_new(0);
    if (!lower_case) {
        ++num_new;
    }
    if (!upper_case) {
        ++num_new;
    }
    if (!digit) {
        ++num_new;
    }

    int num_edits(0);
    if (s.size() < 6) {
        int num_inserts = 6 - s.size();
        // Some of the inserts can also satisfy num_new.
        num_new -= min(num_new, num_inserts);
        // Some of the inserts can break run lengths.
        for (int i = 0; i < run_lengths.size(); ++i) {
            int rl = run_lengths[i];
            while (num_inserts > 0 && rl >= 3) {
                --num_inserts;
                ++num_edits;
                rl -= 2;
            }
            while (num_new > 0 && rl >= 3) {
                --num_new;
                ++num_edits;
                rl -= 2;
            }
            run_lengths[i] = rl;
        }
        num_edits += num_inserts;
    } else if (s.size() > 20) {
        int num_deletes = s.size() - 20;
        // Some of the deletes can break run lengths at the same priority as substitutions.
        for (int i = 0; i < run_lengths.size(); ++i) {
            int rl = run_lengths[i];
            while (num_new > 0 && rl >= 3) {
                --num_new;
                ++num_edits;
                rl -= 3;
            }
            if (rl >= 3 && num_deletes > 0 && rl % 3 == 0) {
                --num_deletes;
                ++num_edits;
                rl -= 1;
            }
            run_lengths[i] = rl;
        }
        // Use the remainder of our deletion budget by priority.
        // This is given by number of deletes needed to break a repeat.
        for (int i = 0; i < run_lengths.size(); ++i) {
            int rl = run_lengths[i];
            if (rl >= 3 && num_deletes >= 2 && rl % 3 == 1) {
                num_deletes -= 2;
                num_edits += 2;
                rl -= 2;
            }
            run_lengths[i] = rl;
        }
        for (int i = 0; i < run_lengths.size(); ++i) {
            int rl = run_lengths[i];
            while (rl >= 3 && num_deletes >= 3 && rl % 3 == 2) {
                num_deletes -= 3;
                num_edits += 3;
                rl -= 3;
            }
            run_lengths[i] = rl;
        }
        num_edits += num_deletes;
    }

    // All remaining repeats will now be broken by substitutions.
    int num_replace(0);
    for (int rl : run_lengths) {
        num_replace += rl / 3;
    }
    num_edits += num_replace;

    // Some num_new can be satisfied by above substitutions.
    num_new -= min(num_new, num_replace);
    num_edits += num_new;

    return num_edits;

}


int main()
{
    string pass = "aA1";
    string pass2 = "aaaaaaaAAAAAA6666bbbbaaaaaaABBC";

    cout << strongPasswordChecker(pass2)<<endl;


}