/*/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;

int pp[300000] = { 0, };
int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

	 // freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		dq.clear();
		memset((void*)pp, 0, sizeof(pp));
		Answer = 0;

		int N, max = 0, min = 0;
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			int curr;
			cin >> curr;
			dq.push_back(curr);
			if (max < curr)
				max = curr;
		}

		sort(dq.begin(), dq.end());

		int pp_n = 0;
		for (int i = 0; !dq.empty(); i++)
		{
			if (dq.front() + N <= max)
				pp_n++;
			pp[i] = dq.front();
			dq.pop_front();
		}

		Answer = N - pp_n;

		for(int j = pp_n; j < N - 1; j++)
		{
			if (pp[j + 1] - (j + 1) > pp[j])
				Answer--;
			else
			{
				for (int i = j + 1; i < N; i++)
				{
					if (pp[i] - pp[j] > i || pp[i] - i > pp[i - 1])
					{
						Answer--;
						break;
					}
				}
			}
		}

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}