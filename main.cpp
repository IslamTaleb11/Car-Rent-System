#include<iostream>
#include<fstream>
#include <windows.h>

using namespace std;
// ======================================= Variables ===================================//

int choice;


// =====================================================================================//

class Functions {

private:
	string acc_name, acc_email, acc_pass, name, email, pass;
	bool found = false;
public:

	void create_acc() {

		cout << " ============================================ " << endl;
		cout << " Enter Your Name: ";
		cin >> acc_name;
		cout << endl;
		cout << " Enter Your Email Address: ";
		cin >> acc_email;
		cout << endl;
		cout << " Enter Your Password: ";
		cin >> acc_pass;
		cout << endl;

		ifstream infile("users.txt");

		while (infile >> email >> pass)
		{
			if (acc_email == email)
			{
				found = true;
			}
		}
		infile.close();

		if (found)
		{
			cout << " This Email Is Already Exist, Try Another One. " << endl;
			create_acc();
		}

		else
		{
			ofstream infile("users.txt", ios::app);
			infile << acc_email << " " << acc_pass << " " << acc_name << endl;
			infile.close();
			cout << " Your Account Have Been Created Successfully. " << endl;
			dis_acc();
		}






	}

	void login_acc() {
		string email, pass, name;
		bool login = false;
		cout << " Enter Your Email Address To Login: ";
		cin >> acc_email;
		cout << endl;
		cout << " Enter Your Password: ";
		cin >> acc_pass;
		cout << endl;

		ifstream infile("users.txt");
		while (infile >> email >> pass >> name)
		{
			if (acc_email == email && acc_pass == pass)
			{
				login = true;

			}
		}

		infile.close();

		if (login)
		{
			cout << " You have Been Loged In Successfully. " << endl;
			dis_acc();
		}

		else
		{
			cout << " Wrong Email Or Password, Please try Again. " << endl;
			login_acc_again();
		}

	}


	void login_acc_again() {

		string email, pass, name;
		bool login = false;
		static int trys = 5;
		cout << " Enter Your Email Address To Login: ";
		cin >> acc_email;
		cout << endl;
		cout << " Enter Your Password: ";
		cin >> acc_pass;
		cout << endl;

		ifstream infile("users.txt");
		while (infile >> email >> pass >> name)
		{
			if (acc_email == email && acc_pass == pass)
			{
				login = true;

			}
		}

		infile.close();

		if (login)
		{
			cout << " You have Been Loged In Successfully. " << endl;
			dis_acc();
		}

		else
		{
			trys--;
			cout << " Wrong Email Or Password, Please try Again. " << endl;
			if (trys == 0)
			{
				cout << " Your Tries End! " << endl;
				Sleep(120);
			}
			else
			{
				login_acc_again();
			}
			
		}
	}

	void forget_pass() {
		string email_in, pass_in;
		bool found = false;
		system("cls");
		cout << " ======================================================== " << endl;
		cout << " Enter Your Email to Recover Your Password: ";
		cin >> email;
		ifstream Infile("users.txt");
		while (Infile >> email_in >> pass_in >> name)
		{
			if (email == email_in)
			{
				found = true;
				cout << " Your Email is: " << email_in << " And Your Password is: " << pass_in << endl;
				login_acc();
			}

		}
		Infile.close();
		if (!found)
		{
			cout << " Wrong Email Address. " << endl;
			exit(0);
		}


	}

	void dis_acc() {

		cout << " ================================================== " << endl;
		cout << "                  Welcome Again.                    " << endl;
		cout << " ================================================== " << endl;
		cout << "              Choose The Service You Want.          " << endl;
		cout << " ================================================== " << endl;
		cout << " 1. Show List Of Our Cars.                          " << endl;
		cout << " 2. Rent A Car.                                     " << endl;
		cout << " 3. Compare The prices of Our Rental Cars.          " << endl;
		cout << " 4. Exit.                                           " << endl;
		cout << " ================================================== " << endl;
		cin >> choice;
		
		switch (choice)
		{
		case 1:
			cars_list();
			break;
		case 2:
			rent_car();
			break;
		case 3:
			compare_prices();
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << " Enter A Valid Option. " << endl;
			break;
		}
	}

	void cars_list() {

		
		cout << " ===================================================== " << endl;
		cout << "                     Our Available Cars:               " << endl;
		cout << " 1. BMW M5 ==> 200$/Day                                " << endl;
		cout << " 2. BMW M4 ==> 180$/Day                                " << endl;
		cout << " 3. BENTLY ==> 300$/Day                                " << endl;
		cout << " 4. VOLVO Vovo ==> 70$/Day                             " << endl;
		cout << " ===================================================== " << endl;
		cout << " Press 1 to go back to Service Page: ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1 :
			dis_acc();
			break;
		default:
			cout << " Enter A Valid Choice! " << endl;
			system("cls");
			cars_list();
			break;
		}


	}

	int day_rent;
	string car1 = "BMW M5";
	string car2 = "BMW M4";
	string car3 = "BENTLY";
	string car4 = "VOLVO vovo";

	void rent_car() {
		int confirm;

		cout << " ================================================================ " << endl;
		cout << "                Welcome To The Rent Car Page                      " << endl;
		cout << " ================================================================ " << endl;
		cout << "                     Our Available Cars:                          " << endl;
		cout << "1. " << car1 << " ==> 200$ / Day                                  " << endl;
		cout << "2. " << car2 << " ==> 180$ / Day                                  " << endl;
		cout << "3. " << car3 << " ==> 300$ / Day                                  " << endl;
		cout << "4. " << car4 << " VOLVO Vovo ==> 70$ / Day                        " << endl;
		cout << " ================================================================ " << endl;
		cout << " Choose The Car You Wanna Rent(1/4): ";
		cin >> choice;
		cout << endl;
		cout << " Choose How Many Days You Wanna Rent The Car: ";
		cin >> day_rent;
		cout << endl;

		if (choice == 1 && day_rent == 1)
		{
			int result = 200;
			cout << " You Have Choosen " << car1 << " For " << day_rent << " Day , And Global Price is: " << result << endl;
			cout << " Confirm You Wanna Pay, Enter 1 If Yes. ";
			cin >> confirm;
			cout << endl;
			switch (confirm)
			{
			case 1:
				system("cls");
				send_money();
				dis_acc();
				break;
			default:
				rent_car();
				break;
			}

			
		}

		else if (choice == 2 && day_rent == 1)
		{
			int result = 180;
			cout << " You Have Choosen " << car2 << " For " << day_rent << " Day , And Global Price is: " << result << endl;
			cout << " Confirm You Wanna Pay, Enter 1 If Yes. ";
			cin >> confirm;
			cout << endl;
			switch (confirm)
			{
			case 1:
				system("cls");
				send_money();
				dis_acc();
				break;
			default:
				rent_car();
				break;
			}

		}

		else if (choice == 3 && day_rent == 1)
		{
			int result = 300;
			cout << " You Have Choosen " << car3 << " For " << day_rent << " Day , And Global Price is: " << result << endl;
			cout << " Confirm You Wanna Pay, Enter 1 If Yes. ";
			cin >> confirm;
			cout << endl;
			switch (confirm)
			{
			case 1:
				system("cls");
				send_money();
				dis_acc();
				break;
			default:
				rent_car();
				break;
			}

		}

		else if (choice == 4 && day_rent == 1)
		{
			int result = 70;
			cout << " You Have Choosen " << car4 << " For " << day_rent  << " Day" << " , And Global Price is: " << result << endl;
			cout << " Confirm You Wanna Pay, Enter 1 If Yes. ";
			cin >> confirm;
			cout << endl;
			switch (confirm)
			{
			case 1:
				system("cls");
				send_money();
				dis_acc();
				break;
			default:
				rent_car();
				break;
			}

		}

		else if (choice == 1 && day_rent == 2)
		{
			int result = 200*2;
			cout << " You Have Choosen " << car1 << " For " << day_rent << " Day" << " , And Global Price is: " << result << endl;
			cout << " Confirm You Wanna Pay, Enter 1 If Yes. ";
			cin >> confirm;
			cout << endl;
			switch (confirm)
			{
			case 1:
				system("cls");
				send_money();
				dis_acc();
				break;
			default:
				rent_car();
				break;
			}

		}

		else if (choice == 1 && day_rent == 3)
		{
			int result = 200 * 3;
			cout << " You Have Choosen " << car1 << " For " << day_rent << " Day" << " , And Global Price is: " << result << endl;
			cout << " Confirm You Wanna Pay, Enter 1 If Yes. ";
			cin >> confirm;
			cout << endl;
			switch (confirm)
			{
			case 1:
				system("cls");
				send_money();
				dis_acc();
				break;
			default:
				rent_car();
				break;
			}

		}
		
		else if (choice == 2 && day_rent == 2)
		{
			int result = 180 * 2;
			cout << " You Have Choosen " << car2 << " For " << day_rent << " Day "<<", And Global Price is : " << result << endl;
			cout << " Confirm You Wanna Pay, Enter 1 If Yes. ";
			cin >> confirm;
			cout << endl;
			switch (confirm)
			{
			case 1:
				system("cls");
				send_money();
				dis_acc();
				break;
			default:
				rent_car();
				break;
			}

		}

		else if (choice == 2 && day_rent == 3)
		{
			int result = 180 * 3;
			cout << " You Have Choosen " << car2 << " For " << day_rent << " Day , And Global Price is: " << result << endl;
			cout << " Confirm You Wanna Pay, Enter 1 If Yes. ";
			cin >> confirm;
			cout << endl;
			switch (confirm)
			{
			case 1:
				system("cls");
				send_money();
				dis_acc();
				break;
			default:
				rent_car();
				break;
			}

		}

		else if (choice == 3 && day_rent == 2)
		{
			int result = 300 * 2;
			cout << " You Have Choosen " << car3 << " For " << day_rent << " Day , And Global Price is: " << result << endl;
			cout << " Confirm You Wanna Pay, Enter 1 If Yes. ";
			cin >> confirm;
			cout << endl;
			switch (confirm)
			{
			case 1:
				system("cls");
				send_money();
				dis_acc();
				break;
			default:
				rent_car();
				break;
			}

		}

		else if (choice == 3 && day_rent == 3)
		{
			int result = 300 * 3;
			cout << " You Have Choosen " << car3 << " For " << day_rent << " Day , And Global Price is: " << result << endl;
			cout << " Confirm You Wanna Pay, Enter 1 If Yes. ";
			cin >> confirm;
			cout << endl;
			switch (confirm)
			{
			case 1:
				system("cls");
				send_money();
				dis_acc();
				break;
			default:
				rent_car();
				break;
			}

		}

		else if (choice == 4 && day_rent == 2)
		{
			int result = 70 * 2;
			cout << " You Have Choosen " << car4 << " For " << day_rent << " Day , And Global Price is: " << result << endl;
			cout << " Confirm You Wanna Pay, Enter 1 If Yes. ";
			cin >> confirm;
			cout << endl;
			switch (confirm)
			{
			case 1:
				system("cls");
				send_money();
				dis_acc();
				break;
			default:
				rent_car();
				break;
			}

		}

		else if (choice == 4 && day_rent == 3)
		{
			cout << " You Can't Rent The Car More Then 3 Days. " << endl;
			rent_car();
			int result = 70 * 3;
			cout << " You Have Choosen " << car4 << " For " << day_rent << " Day , And Global Price is: " << result << endl;
			cout << " Confirm You Wanna Pay, Enter 1 If Yes. ";
			cin >> confirm;
			cout << endl;
			switch (confirm)
			{
			case 1:
				system("cls");
				send_money();
				dis_acc();
				break;
			default:
				rent_car();
				break;
			}

		}

		else
		{
			system("cls");
			cout << " Enter A Valid Option. " << endl;
			cout << " Note: That You Can't Rent A Car For More Then 3 Days. " << endl;
			rent_car();
		}

	}


	void send_money() {
		int car1_m = 200;
		int car2_m = 180;
		int car3_m = 300;
		int car4_m = 70;

		ofstream Money("money.txt", ios::app);
		ifstream Infile("users.txt");

		if (choice == 1 && day_rent == 1)
		{
			int result = 200;
			Money << result << endl;
			cout <<" You Have Been paid Successfully. " << endl;
				
			
		}

		else if (choice == 2 && day_rent == 1)
		{
			int result = 180;
			Money << result << endl;
			cout <<" You Have Been paid Successfully. " << endl;
		}

		else if (choice == 3 && day_rent == 1)
		{
			int result = 300;
			Money << result << endl;
			cout << " You Have Been paid Successfully. " << endl;
		}


		else if (choice == 4 && day_rent == 1)
		{
			int result = 70;
			Money << result << endl;
			cout << " You Have Been paid Successfully. " << endl;
		}

		else if (choice == 1 && day_rent == 2)
		{
			int result = 200 * 2;
			Money << result << endl;
			cout << " You Have Been paid Successfully. " << endl;
		}

		else if (choice == 1 && day_rent == 3)
		{
			int result = 200 * 3;
			Money << result << endl;
			cout << " You Have Been paid Successfully. " << endl;
		}

		else if (choice == 2 && day_rent == 2)
		{
			int result = 180 * 2;
			Money << result << endl;
			cout << " You Have Been paid Successfully. " << endl;
		}

		else if (choice == 2 && day_rent == 3)
		{
			int result = 180 * 3;
			Money << result << endl;
			cout << " You Have Been paid Successfully. " << endl;
		}

		else if (choice == 3 && day_rent == 2)
		{
			int result = 300 * 2;
			Money << result << endl;
			cout << " You Have Been paid Successfully. " << endl;
		}

		else if (choice == 3 && day_rent == 3)
		{
			int result = 300 * 3;
			Money << result << endl;
			cout << " You Have Been paid Successfully. " << endl;
		}

		else if (choice == 4 && day_rent == 2)
		{
			int result = 70 * 2;
			Money << result << endl;
			cout << " You Have Been paid Successfully. " << endl;
		}


		else if (choice == 4 && day_rent == 3)
		{
			int result = 70 * 3;
			Money << result << endl;
			cout << " You Have Been paid Successfully. " << endl;
		}

		Money.close();

	}

	void compare_prices() {
		int choice1;
		int choice2;

		int car1_m = 200;
		int car2_m = 180;
		int car3_m = 300;
		int car4_m = 70;
		cout << " ======================================================== " << endl;
		cout << "             Welcome To Compare prices page.              " << endl;
		cout << " ======================================================== " << endl;
		cout << "                     Our Cars List:                       " << endl;
		cout << " ======================================================== " << endl;
		cout << "1. " << car1 << " ==> 200$ / Day                                  " << endl;
		cout << "2. " << car2 << " ==> 180$ / Day                                  " << endl;
		cout << "3. " << car3 << " ==> 300$ / Day                                  " << endl;
		cout << "4. " << car4 << " VOLVO Vovo ==> 70$ / Day                        " << endl;
		cout << " Enter The Number Of The First Car For Comparing:                 ";
		cin >> choice1;
		cout << endl;
		cout << " Enter The Number Of The Second Car Now:                          ";
		cin >> choice2;
		cout << endl;

		if (choice1 == 1 && choice2 == 2)
		{
			int result = car2_m - car1_m;
			cout << " The Difference Between " << car1 << " and " << car2 << " is " << result << "$" << endl;
			dis_acc();
		}

		else if (choice1 == 1 && choice2 == 3)
		{
			int result = car3_m - car1_m;
			cout << " The Difference Between " << car1 << " and " << car3 << " is " << result << "$" << endl;
			dis_acc();
		}

		else if (choice1 == 1 && choice2 == 4)
		{
			int result = car1_m - car4_m;
			cout << " The Difference Between " << car1 << " and " << car4 << " is " << result << "$" << endl;
			dis_acc();
		}

		else if (choice1 == 2 && choice2 == 1)
		{
			int result = car1_m - car2_m;
			cout << " The Difference Between " << car2 << " and " << car1 << " is " << result << "$" << endl;
			dis_acc();
		}



		else if (choice1 == 2 && choice2 == 3)
		{
			int result = car3_m - car2_m;
			cout << " The Difference Between " << car2 << " and " << car3 << " is " << result << "$" << endl;
			dis_acc();
		}

		else if (choice1 == 2 && choice2 == 4)
		{
			int result = car2_m - car4_m;
			cout << " The Difference Between " << car2 << " and " << car4 << " is " << result << "$" << endl;
			dis_acc();
		}

		else if (choice1 == 3 && choice2 == 1)
		{
			int result = car3_m - car1_m;
			cout << " The Difference Between " << car3 << " and " << car1 << " is " << result << "$" << endl;
			dis_acc();
		}

		else if (choice1 == 3 && choice2 == 2)
		{
			int result = car3_m - car2_m;
			cout << " The Difference Between " << car3 << " and " << car2 << " is " << result << "$" << endl;
			dis_acc();
		}

		else if (choice1 == 3 && choice2 == 4)
		{
			int result = car3_m - car4_m;
			cout << " The Difference Between " << car3 << " and " << car4 << " is " << result << "$" << endl;
			dis_acc();
		}

		else if (choice1 == 4 && choice2 == 1)
		{
			int result = car1_m - car4_m;
			cout << " The Difference Between " << car4 << " and " << car1 << " is " << result << "$" << endl;
			dis_acc();
		}

		else if (choice1 == 4 && choice2 == 2)
		{
			int result = car2_m - car4_m;
			cout << " The Difference Between " << car4 << " and " << car2 << " is " << result << "$" << endl;
			dis_acc();
		}

		else if (choice1 == 4 && choice2 == 3)
		{
			int result = car3_m - car4_m;
			cout << " The Difference Between " << car4 << " and " << car3 << " is " << result << "$" << endl;
			dis_acc();
		}

		else
		{
			cout << " There Is Something Wrong! Try Again. " << endl;
			compare_prices();
		}




	}
};

class Menu : public Functions {
private:


public:
	Menu() {

		cout << " ===================================================== " << endl;
		cout << "               Welcome To The Car Rental Shop          " << endl;
		cout << " ===================================================== " << endl;
		cout << "                     Choose An Option                  " << endl;
		cout << endl;
		cout << " 1. Create Account.                                    " << endl;
		cout << " 2. Login.                                             " << endl;
		cout << " 3. Forget Password.                                   " << endl;
		cout << " 4. Exit.                                              " << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			create_acc();
			break;
		case 2:
			login_acc();
			break;
		case 3:
			forget_pass();
			break;
		case 4 :
			exit(0);
			break;
		default:
			cout << " Enter A Valid Option! " << endl;

			Menu();
			break;
		}
		
		


	}

};

int main(){

	Menu ob;


	return 0;
}