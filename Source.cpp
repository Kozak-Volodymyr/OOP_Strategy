#include<iostream>
#include<string>
using namespace std;
class Strategy {
public:
	 virtual ~Strategy() {};
	 virtual void DoAlgo()=0;
};
class Context
{
private:
	 Strategy *strat;
public:
	 Context(Strategy*strategy = NULL) :strat(strategy){}
	 ~Context() {
		  delete this->strat;
	 }
	 void set_str(Strategy*strategy) {
		  delete this->strat;
		  this->strat = strategy;
	 }
	 void Action() {
		  this->strat->DoAlgo();
	 }
	 };

class Bank{
public:
	 int termin;
	 double rich;
	 string name;
	 double suma;
public:
	 Bank() {};
	 Bank(double sum, string nam, int ter, double ric) {
		  suma = sum;
		  name = nam;
		  termin = ter;
		  rich = ric;
	 }
	  double Vids() {
		  double Vids;
		  Vids = termin * rich*suma;
		  return Vids;
	 }
	 void Print() {
		  cout << "\n Ім'я:" << name << endl;
		  cout << "\n Сума вкладу:" << suma << endl;
		  cout << "\n Сума:" << Vids() << endl;
	 }
};
class str :public Strategy, public Bank {
public:
		  void DoAlgo() {
				int n,l;
				cout << "\n Введіть кількість елементів:";
				cin >> n;
				getchar();
				Bank *p = new Bank[n];
				cout << "Введіть  дані\n";
				for (int i = 0; i < n; i++) {
					 string name;
					 int ter;
					 double rich, suma;
					 cout << "\n Ім'я:" << endl;
					 getline(cin,name);
					 cout << "Сума депозиту:" << endl;
					 scanf_s("%lf", &suma);
					 cout << "Термін:" << endl;
					 scanf_s("%d", &ter);
					 cout << "Річна ставка:" << endl;
					 scanf_s("%lf", &rich);
					 getchar();
					 p[i] = Bank(suma, name, ter, rich);
				}
				for (int i = 0; i < n; i++) {
					 l = 1;
					 Bank copy;
					 if ((i + 1) == n)
						  break;
					 for (; (i + l) < n; l++) {
						  if (p[i].Vids() < p[i + l].Vids()) {
								copy = p[i];
								p[i] = p[i + l];
								p[i + l] = copy;
								i = -1;
								l = n;
						  }
					 }
				}
				for (int i = 0; i < n; i++) {
					 p[i].Print();
				}
	 }
};
class Bank2 {
private:
	 int termin;
	 double *Massyv;
	 int n;
	 double sum;
	 string names;
public:
	 Bank2() {};
	 Bank2(double a, string name, int ter) {
		  sum = a;
		  names = name;
		  termin = ter;
		  n = int((ter / 4));
		  Massyv = new double[n];
		  for (int i = 0; i < n; i++) {
				cout << "Введіть " << i + 1 << " квартал:";
				cin >> Massyv[i];

		  }
	 }
	 double Vids() {
		  double Vids;
		  double k = 0;
		  for (int i = 0; i < n; i++) {
				k = k + ((sum*(Massyv[i] / 100)) / 4);
		  }
		  return sum + k;
	 }
	 void Print() {
		  cout << "\n Ім'я:" << names << endl;
		  cout << "\n Сума вкладу:" << sum << endl;
		  cout << "\n Сума:" << Vids() << endl;
		  cout << "\n Квартальна ставка:"<<endl;
		  for (int i = 0; i < n; i++) {
				 cout<<Massyv[i] << endl;
		  }
	 }
};
class str2 :public Strategy, public Bank2 {
public:
	 void DoAlgo() {
		  int d, l;
		  cout << "\n Введіть кількість елементів:";
		  cin >> d;
		  Bank2*m = new Bank2[d];
		  for (int i = 0; i < d; i++) {
				string name;
				int term;
				double sum;
				getchar();
				cout << "\n Ім'я:" << endl;
				getline(cin,name);
				cout << "Сума депозиту:" << endl;
				scanf_s("%lf", &sum);
				cout << "Термін:" << endl;
				scanf_s("%d", &term);
				m[i] = Bank2(sum, name, term);
		  }
		  for (int i = 0; i < d; i++) {
				l = 1;
				Bank2 copy;
				if ((i + 1) == d)
					 break;
				for (; (i + l) < d; l++) {
					 if (m[i].Vids() < m[i + l].Vids()) {
						  copy = m[i];
						  m[i] = m[i + l];
						  m[i + l] = copy;
						  i = -1;
						  l = d;
					 }
				}
		  }
		  for (int i = 0; i < d; i++) {
				m[i].Print();
		  }
	 }
};
int main(){
	 system("chcp 1251");
	 Context *con = new Context(new str);
	 con->Action();
	 con->set_str(new str2);
	 con->Action();
	 delete con;
}