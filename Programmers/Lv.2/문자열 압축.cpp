#include <string>
using namespace std;

int solution(string s) {
	int answer = 10000;
	int divisor = 1;

	while (divisor <= s.length()) {
		string preToken = "";
		string compressedString = "";
		int repeatCount = 1;

		for (int i = 0; i < s.length(); i += divisor) {
			string token = s.substr(i, divisor);

			if (preToken.empty()) {
				preToken = token;
				continue;
			}

			if (preToken != token) {
				string strRepeatCount = repeatCount == 1 ? "" : to_string(repeatCount);

				compressedString += strRepeatCount;
				compressedString += preToken;

				// 최솟값보다 큰 경우는 볼 필요 없으므로 다음 루프로
				if (answer < compressedString.length())
					continue;

				preToken = token;
				repeatCount = 1;
				continue;
			}

			repeatCount++;
		}

		string strRepeatCount = repeatCount == 1 ? "" : to_string(repeatCount);
		compressedString += strRepeatCount;
		compressedString += preToken;
		answer = min(answer, (int)compressedString.length());
		divisor++;
	}


	return answer;
}