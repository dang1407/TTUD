#include<iostream>
#include<vector>

using namespace std;

vector<string> call, from_number, to_number, date, from_time, end_time;
vector<string> query;
string s_call, s_from_number, s_to_number, s_date, s_from_time, s_end_time, s_query;

int checkPhoneNumber(string phoneNumber);
int numberCallsFrom(string fromNumber);
int numberTotalCalls();
int timeCalls(string fromNumber);
void print(vector<string> a){
      for(int i = 0; i < a.size();i++){
            cout << a[i] << " ";
      }
      cout << endl;
}
int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);

      // Dự trữ kích thước để chứa tối đa 1000 cuộc gọi
      call.reserve(1000);
      from_number.reserve(1000);
      to_number.reserve(1000);
      date.reserve(1000);
      from_time.reserve(1000);
      end_time.reserve(1000);
      query.reserve(1000);
      bool check = true;

      // Nhập dữ liệu
      while(check){
            cin >> s_call;
            if(s_call.compare("#") == 0){
                  check = false;
                  break;
            }
            cin >> s_from_number;
            cin >> s_to_number;
            cin >> s_date;
            cin >> s_from_time;
            cin >> s_end_time;

            call.push_back(s_call);
            from_number.push_back(s_from_number);
            to_number.push_back(s_to_number);
            date.push_back(s_date);
            from_time.push_back(s_from_time);
            end_time.push_back(s_end_time);
      }


      // Nhập truy vấn
      check = true;
      // cin >> s_query;
      while(check){
            getline(cin, s_query);
            if(s_query.compare("#") == 0){
                  check = false;
                  break;
            }
            if(s_query.compare("") != 0)
            query.push_back(s_query);
      }

      print(call);
      print(from_number);
      print(to_number);
      print(date);
      print(from_time);
      print(end_time);
      print(query);
      cout << "So query: " <<  query.size() << endl;
      for(int i = 0; i < query.size(); i++){
            //?check_phone_number
            if(query[i].compare("?check_phone_number") == 0){
                  cout << checkPhoneNumber() << endl;
            } else if(query[i].compare("?number_total_calls") == 0){
                  cout << numberTotalCalls() << endl;
            } else if(query[i].substr(0, 18).compare("?number_calls_from") == 0){
                  // cout << " called!\n";
                  // cout << query[i].substr(19,29) << endl;
                  cout << numberCallsFrom(query[i].substr(19,29)) << endl;
            } else if(query[i].substr(0,17).compare("?count_time_calls") == 0){
                  // cout << " called!\n";
                  // cout << query[i].substr(24,34) << endl;
                  cout << timeCalls(query[i].substr(23,33)) << endl;
            }
      }

      cout << query[0];
}


int checkPhoneNumber(){
      for(int i = 0; i < from_number.size(); i++){
            for(int j = 0; j < from_number[i].length(); j++){
                  if(from_number[i][j] < '0' || from_number[i][j] > '9') {
                        return 0;
                  }
            }
      }
      return 1;
}

int numberCallsFrom(string fromNumber){
      int result = 0;
      for(int i = 0; i < from_number.size(); i++){
            if(from_number[i].compare(fromNumber) == 0){
                  result++;
            }
      }
      return result;
}

int numberTotalCalls(){
      return call.size();
}

int timeCalls(string fromNumber){
      int result = 0;
      for(int i = 0; i < from_number.size(); i++){
            if(from_number[i].compare(fromNumber) == 0){
                  int start_hour = (from_time[i][0] - 48)*10 + (from_time[i][1] - 48);
                  int start_minute = (from_time[i][3] - 48)*10 + (from_time[i][4] - 48);
                  int start_second = (from_time[i][6] - 48)*10 + (from_time[i][7] - 48);
                  int end_hour = (end_time[i][0] - 48)*10 + (end_time[i][1] - 48);
                  int end_minute = (end_time[i][3] - 48)*10 + (end_time[i][4] - 48);
                  int end_second = (end_time[i][6] - 48)*10 + (end_time[i][7] - 48);

                  result += (end_hour - start_hour)*3600 + (end_minute - start_minute)*60 + (end_second - start_second);
            }
      }

      return result;
}