#include <iostream>
#include <vector>

using namespace std;

void gale_shapley_algorithm(int n)
{
    vector<vector<int>> Stud_Pref(n + 1, vector<int>(n + 1)); // preference matrix of universities given by students (input matrix)
    vector<vector<int>> Uni_Pref(n + 1, vector<int>(n + 1));  // preference matrix of students given by universities (input matrix)
    vector<vector<int>> Pref(n + 1, vector<int>(n + 1));      // Stores preference between all pairs of students and universities
                                                              // Pref[i][j] tells us about preference of the ith student by the jth university
                                                              // lower value means higher priority
    vector<int> enrolled(n + 1);                              // stores info about students whose enrollment process is completed
    vector<int> present(n + 1);                               // present[i] is the student who is currently enrolled in the ith University
    vector<int> last_uni(n + 1);                              // last_uni[i] stores info about the last university student i applied to

    cout << "Enter Preference List for Student:\n";
    // taking an nxn matrix as input
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> Stud_Pref[i][j];
        }
    }

    cout << "Enter Preference List for University:\n";
    // taking an nxn matrix as input
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> Uni_Pref[i][j];
        }
    }

    // initializing arrays to 0
    for (int i = 0; i <= n; ++i)
    {
        present[i] = 0;
        enrolled[i] = 0;
        last_uni[i] = 0;
    }

    // calculating Pref[][]
    for (int j = 1; j <= n; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            Pref[Uni_Pref[j][i]][j] = i;
        }
    }

    // loop runs until all the pairs are matched, i.e. all the students are enrolled
    while (true)
    {
        bool flag = true;
        for (int i = 1; i <= n; ++i)
        {
            // if the ith student is not enrolled
            if (!enrolled[i])
            {
                flag = false;
                break;
            }
        }

        // if all students are enrolled then break the loop
        if (flag)
        {
            break;
        }

        // this loop iterates over each student
        for (int i = 1; i <= n; ++i)
        {
            // checking the enrollment status of the ith student
            if (!enrolled[i])
            {
                // if the ith student is not enrolled anywhere, he applies to a university
                int s = i; // s is the current student
                last_uni[s]++;
                int u = Stud_Pref[s][last_uni[s]]; // u is the university where student s is going to apply based on his preference list
                if (present[u] == 0)
                {
                    // if there is currently no application with university u, then student s gets accepted
                    present[u] = s;
                    enrolled[s] = 1;
                }
            }
        }
    }
//printing the result after all iterations of the above loop
    cout<<"Student	 University\n";
  
	for (int i=1;i<=n;i++) 
    {
        cout<<present[i]<<" "<< i<<endl;
		
	}

}


int main()
{
    
    int n;
   cout<<"Enter the number of student or university required for matching :";
    //printf("Enter the number of student or university required for matching :");
   // scanf("%d",&n);
    cin>>n;
    gale_shapley_algorithm(n);
}
