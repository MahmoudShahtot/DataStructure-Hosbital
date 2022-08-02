#include"fileRecipient and fileDonor.cpp"
#include"fileBlood_information.cpp"
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
vector<Recipient>recipient;
vector<Donor> donor;
vector<Blood_information>blood_information;
string choose;
int index_donor ;
int index_recipient ;

void interface();   
void display_blood(); 
void choose_operation(); 
void Login();     
void Register();   
void search_for_blood();
void return_to(); 
void delete_account();
int check_password();
void update_data();
void request_donation();
void display_data(); 
void bloodtype_request();
void Same_Data(string);

using namespace std;
int main()
{
	fileRecipient FR;
	fileDonor FD;
	file_boold FB;
	FD.read(donor);
	FB.read(blood_information);
	FR.read(recipient);
	FR.write(recipient);
	interface();
	return 0;
}
void interface()
{

	cout << "----------------------------------------------------------------\n";
	cout << "                  Welcome to Bank Blood system \n";
	cout << "----------------------------------------------------------------\n";
	cout << "1-Donor\n";
	cout << "2-Recipient\n\n";
	cout << "Enter:";
	cin >> choose;
	if (choose == "1" || choose == "2")
	{
		int o = 3;
		while (o > 0)
		{
			int a;
			cout << "1-Sign up\n";
			cout << "2-Sign in\n\n";
			cout << "Enter:";
			cin >> a;

			if (a == 1)
			{
				Register();
				break;
			}
			else if(a == 2)
			{
				Login();
				break;
			}

		
	else
	{
		cout << "Please Enter a correct choose!!!\n\n";
	}
	o--;
	}
}

	
}
void Register()
{

	int id, age;
	Donor d;
	Recipient r;
	fileRecipient FR;
	fileDonor FD;
	string Name, Mail, Password, Gender, Blood_type, Disease, Medicine, Date, Hospital, Doctor, check,go_next;

	
	if (choose == "1" || choose == "2")
	{
		cout << "Enter your Age:";
		cin >> age;
		cout << endl;

		if (choose == "1")
		{
			if (age < 18 || age > 60)
			{
				cout << "You cannot donate blood because your age is not appropriate and blood donation may cause health damage to you\n";
				cout << "*******************Thank you for your donation at this age*******************\n";
				Register();
			}
		}
		cout << "Enter your Name:";
		cin >> Name;
		cout << endl;
		cout << "Enter your Password:";
		cin >> Password;
		cout << endl;
		cout << "Enter your Id:";
		cin >> id;
		cout << endl;
		cout << "Enter your Mail:";
		cin >> Mail;
		cout << endl;
		cout << "Enter your Gender:";
		cin >> Gender;
		cout << endl;
		cout << "Enter your Blood type:";
		cin >> Blood_type;
		transform(Blood_type.begin(), Blood_type.end(), Blood_type.begin(), ::toupper);
		cout << endl;
		if (choose == "1")
		{
			int counter = 3;
			while (counter > 0)
			{
				cout << "Do you have a disease ?\n";
				cout << "1-yes\n";
				cout << "2-no\n\n";
				cout << "Enter:";
				cin >> check;
				transform(check.begin(), check.end(), check.begin(), ::tolower);
				if (check == "1" || check == "2" || check == "yes" || check == "no" )
				{
					break;
				}
				else
				{
					cout << "Please Enter a correct choose!!!\n\n";
				}
				counter--;
				if (counter == 0)
				{
					cout << "Error\n";
					Register();
				}
			}

			if (check == "1" || check == "yes")
			{
				cout << "Please Write your disease:";
				cin >> Disease;
				cout << endl;
				int counter = 3;
				while (counter > 0)
				{
					cout << "Do you take any medicine ?\n";
					cout << "1-yes\n";
					cout << "2-no\n\n";
					cout << "Enter:";
					cin >> check;
					transform(check.begin(), check.end(), check.begin(), ::tolower);
					if (check == "1" || check == "2" || check == "yes" || check == "no")
					{
						break;
					}
					else
					{
						cout << "Please Enter a correct choose!!!\n\n";
					}
					counter--;
					if (counter == 0)
					{
						cout << "Error\n";
						Register();
					}
				}
				if (check == "1" || check == "yes")
				{
					cout << "Please Wite your medicine that you take:";
					cin >> Medicine;
					cout << endl;
				}
				else
				{
					Medicine = "null";
				}
			}
			else
			{
				Disease = "null";
				Medicine = "null";
			}
			cout << "Enter your Date:";
			cin >> Date;

			d.setId(id);
			d.setPassword(Password);
			d.setName(Name);
			d.setMail(Mail);
			d.setAge(age);
			d.setGender(Gender);
			d.setBlood_type(Blood_type);
			d.setDisease(Disease);
			d.setMedicine(Medicine);
			d.setDate(Date);
			donor.push_back(d);
			FD.write(donor);
		}
		else
		{

			cout << "Enter your Hospital:";
			cin >> Hospital;
			cout << endl;
			cout << "Enter your Doctor:";
			cin >> Doctor;
			cout << endl;

			r.setId(id);
			r.setPassword(Password);
			r.setName(Name);
			r.setMail(Mail);
			r.setAge(age);
			r.setGender(Gender);
			r.setBlood_type(Blood_type);
			r.setHospital(Hospital);
			r.setDoctor(Doctor);
			recipient.push_back(r);
			FR.write(recipient);

		}
	}
	else
	{
		cout << "Please Enter a correct choose!!!\n\n";
		Register();
	}
	cout << "successfully registered\n";
	cout << "To go to Login 1 \n";
	cout << "To return to the main menu 2 \n";
	cin >> go_next;
	if (go_next == "1")
	{
		Login();
	}
		
		else
		{
			interface();
		}
}
void Login()
{

	int id;
	string password;
	bool found = false;
	cout << "----------------------------" << endl;
	cout << "Enter your user id : ";
	cin >> id;
	cout << "Enter your password : ";
	cin >> password;
	cout << "----------------------------" << endl;
	if (choose == "1")
	{
		
		for (int i = 0; i < donor.size(); i++)
		{

			if (id == donor[i].getId() && password == donor[i].getPassword()) {
				index_donor = i;
				found = true;
				choose_operation();
			}
		}
		if (found == false) {
			cout << "user not found" << endl;
			Login();
		}
		found = false;
	}
	else if (choose == "2")
	{
		for (int i = 0; i < recipient.size(); i++) {

			if (id == recipient[i].getId() && password == recipient[i].getPassword()) {
				index_recipient = i ;
				found = true;
				choose_operation();

			}
		}
		if (found == false) {
			cout << "user not found\n" << endl;
			Login();
		}
		found = false;
	}
}
void choose_operation()
{
	if (choose == "2")
	{
		int enter;
		cout << endl;
		cout << "***********Operations**************\n";
		cout << "1-Display your data\n";
		cout << "2-Display all blood data\n";
		cout << "3-Search for the availability\n";
		cout << "4-Rquest blood type\n";
		cout << "5-Update your account\n";
		cout << "6-Delete your account\n";
		cout << "7-Logout\n";
		cout << "8-Exit the program\n\n";
		cout << "Enter your operation:";
		cin >> enter;
		switch (enter)
		{
		case 1:
			cout << "****************************Your Data***************************\n";
			display_data();
			break;
		case 2:
			cout << "****************************Data Blood***************************\n";
			display_blood();
			break;
		case 3:
			cout << "****************************Search for blood***************************\n";
			search_for_blood();
			break;
		case 4:
			cout << "****************************Request Blood***************************\n";
			bloodtype_request();
			break;
		case 5:
			cout << "****************************Update data***************************\n";
			update_data();
			break;
		case 6:
			cout << "****************************Delete Account***************************\n";
			delete_account();
			break;
		case 7:
			interface();
			break;
		case 8:
			exit(0);
		default:
			cout << "Failed! Please Enter a correct choose\n\n";
			choose_operation();
			break;
		}
	}
	else
	{
		int enter;
		cout << endl;
		cout << "****************************Operations***************************\n";
		cout << "1-Display your data\n";
		cout << "2-Apply donation request\n";
		cout << "3-Update your account\n";
		cout << "4-Delete your account\n";
		cout << "5-Logout\n";
		cout << "6-Exit the program\n\n";
		cout << "Enter your operation:";
		cin >> enter;
		switch (enter)
		{
		case 1:
			cout << "****************************Your Data***************************\n";
			display_data();
			break;
		case 2:
			cout << "****************************request donation***************************\n";
			request_donation();
			break;
		case 3:
			cout << "****************************Update data***************************\n";
			update_data();
			break;
		case 4:
			cout << "****************************Delete Account***************************\n";
			delete_account();
			break;
		case 5:
			interface();
			break;
		case 6:
			exit(0);
			break;
		default:
			cout << "Failed! Please Enter a correct choose\n\n";
			choose_operation();
			break;

		}
	}

}
void display_blood()
{
	cout << "-------------------------------------------------------------------\n";
	cout << "Blood  :" << "\t" << "Type" << "\t" << "Quantity" << "\t" << "Received date" << "\t" << "Expiry date"  << endl;
	cout << "-------------------------------------------------------------------\n";

	for (int i = 0; i < blood_information.size(); i++)
	{

		cout << "Blood " << i+1 << "  |" << "\t" << blood_information[i].gettype() << "\t" << "   " << blood_information[i].getQuantity() << "\t\t" << blood_information[i].getreceived_date() << "\t\t" << blood_information[i].getexpiry_date() << endl;
		cout << "-------------------------------------------------------------------\n";
		
	}
	return_to();
	
}

void search_for_blood()
{
	string type;
	bool check2 = false;
	
	cout << "Enter the blood type:";
	cin >> type;
	transform(type.begin(), type.end(), type.begin(), ::toupper);
	for (int i = 0; i < blood_information.size(); i++)
	{
		if (type == blood_information[i].gettype())
		{
			cout << "Successful operation! This blood type is available\n\n";
			check2 = true;
			return_to();
		}
	}
	if (check2 == false)
	{
		cout << "This blood type is not available!\n\n";
		return_to();
	}
	
}
void delete_account()
{
	string password;
	fileRecipient FR;
	fileDonor FD;
	bool found = false;
	int count = 3;
	cout << "----------------------------" << endl;
	cout << "Enter your password : ";
	cin >> password;
	cout << "----------------------------" << endl;
	if (choose == "1")
	{
		if (password == donor[index_donor].getPassword())
		{
			found = true;
			donor.erase(donor.begin() + index_donor );
			cout << "Your account is deleted\n\n";
			FD.write(donor);
			interface();
		}
		if (found == false)
		{
			if (count > 0)
			{
				cout << "Wrong password! please Try again\n" << endl;
				delete_account();
			}
			else
			{

				choose_operation();
			}
			count--;
		}
		found = false;
	}
	else
	{
		if (password == recipient[index_recipient].getPassword())
		{
			found = true;
			recipient.erase(recipient.begin() + index_recipient );
			cout << "Your account is deleted\n\n";
			FR.write(recipient);
			interface();

		}

		if (found == false) {
			
			if (count > 0)
			{
				cout << "Wrong password! please Try again\n" << endl;
				delete_account();
			}
			else
			{

				choose_operation();
			}
			count--;
		}
		found = false;
	}
}

void return_to()
{
	string character;

	cout << "To return to the previous menu press B !\n";
	cout << "To logout press L !\n\n";
	cout << "Enter:";
	cin >> character;
	int o = 3;
	while (o > 0)
	{
		if (character == "B")
		{
			choose_operation();
			break;
		}
		else if (character == "L")
		{
			interface();
			break;
		}
		else
		{
			cout << "Failed! Please try again!\n\n";
		}
		o--;
	}
	choose_operation();
}
void update_data()
{
	string check_update,check, Disease, Medicine, Date, Hospital, Doctor;
	fileRecipient Fr;
	fileDonor Fd;
	cout << "Do you want to continue??\n";
	cout << "1-yes\n";
	cout << "2-no\n\n";
	cout << "Enter:";
	cin >> check;
	transform(check.begin(), check.end(), check.begin(), ::tolower);
	if (check == "yes"|| check == "1")
	{
		cout << "1-Update your id\n";
		cout << "2-Update your password\n";
		cout << "3-Update your name\n";
		cout << "4-Update your Age\n";
		cout << "5-Update your mail\n";
		cout << "6-Update your gender\n";
		cout << "7-Update your Blood_type\n";
		if (choose == "1")
		{
			cout << "8-Update your disease\n";
			cout << "9-Update your Date\n";
			cout << "10-Return to\n\n";
			cout << "Enter the operation number:";
			cin >> check_update;
			if (check_update == "1" || check_update == "2" || check_update == "3" || check_update == "4" || check_update == "5" || check_update == "6" || check_update == "7")
			{
				Same_Data(check_update);
			}
			else if (check_update == "8")
			{
				cout << "Enter The Disease :";
				cin >> Disease;
				string check_medic;
				cout << "Do you take a medicine?\n";
				cout << "1-yes\n";
				cout << "2-no\n\n";
				cout << "Enter:";
				cin >> check_medic;
				transform(check_medic.begin(), check_medic.end(), check_medic.begin(), ::tolower);
				if (check_medic == "1" || check_medic == "yes")
				{
					cout << "Enter The Medicine :";
					cin >> Medicine;
				}
				else if (check_medic == "no" || check_medic == "2")
				{
					Medicine = donor[index_donor].getMedicine();
				}
				else
				{
					cout << "Failed! Please try again!\n\n";
					update_data();
				}
				if (check_password() == 1)
				{
					donor[index_donor].setMedicine(Medicine);
					donor[index_donor].setDisease(Disease);
				}
				else
				{
					cout << "Failed! Please try again!\n\n";
					update_data();
				}

			}
			else if (check_update == "9")
			{
				cout << "Enter date :";
				cin >> Date;
				if (check_password() == 1)
				{
					donor[index_donor].setDate(Date);
				}
				else
				{
					cout << "Failed! Please try again!\n\n";
					update_data();
				}

			}
			else if (check_update == "10")
			{
				return_to();

			}

			else
			{
				cout << "Failed! Please try again!\n\n";
				update_data();
			}

			Fd.write(donor);
		}

		else
		{
			cout << "8-Update your Hospital\n";
			cout << "9-Update your Doctor\n";
			cout << "10- Return To\n\n";
			cout << "Enter the operation number:";
			cin >> check_update;

			if (check_update == "1" || check_update == "2" || check_update == "3" || check_update == "4" || check_update == "5" || check_update == "6" || check_update == "7")
			{
				Same_Data(check_update);
			}
			else if (check_update == "8")
			{
				cout << "Enter The Hospital:";
				cin >> Hospital;
				if (check_password() == 2)
				{
					recipient[index_recipient].setHospital(Hospital);
				}
				else
				{
					cout << "Failed! Please try again!\n\n";
					update_data();
				}

			}
			else if (check_update == "9")
			{
				cout << "Enter The Doctor:";
				cin >> Doctor;
				if (check_password() == 2)
				{
					recipient[index_recipient].setDoctor(Doctor);
				}
				else
				{
					cout << "Failed! Please try again!\n\n";
					update_data();
				}

			}
			else if (check_update == "10")
			{
				return_to();

			}
			else
			{
				cout << "Failed! Please try again!\n\n";
				update_data();
			}

			Fr.write(recipient);
		}



	}
	else if (check == "no"|| check == "2")
	{
		return_to();
	}
	else
	{
		cout << "Failed choose! Try again\n\n";
		update_data();
	}

	cout << "Data has been updated successfully!\n\n";
	choose_operation();

}
int check_password()
{
	int value;
	string check_password;
	cout << "To save the changes, Please Enter your password:";
	cin >> check_password;
	if (choose == "1")
	{
		if (check_password == donor[index_donor].getPassword())
		{
			value = 1;
		}
	}
	else if (choose == "2")
	{
		if (check_password == recipient[index_recipient].getPassword())
		{
			value = 2;
		}
	}
	else 
	{
		value = 3;
	}
	return value;
}

void Same_Data(string type )
{
	int id,Age;
	string  Name, Mail, Password, Gender, Blood_type;
	if (type == "1")
	{
		cout << "Enter The Id :";
		    cin >> id;
			int save = check_password();
		   if  (save == 1 || save == 2 )
		   {
			   if ( save == 1)
			   {
				   donor[index_donor].setId(id);
			   }
			   else 
			   {
				   recipient[index_recipient].setId(id);
			   }
		   }
		   else
		   {
			   cout << "Failed! Please try again!\n\n";
			   update_data();
		   }
	}
	else if (type == "2")
	{
		cout << "Enter The Password :";
		cin >> Password;
		int save = check_password();
		if (save == 1 || save == 2)
		{
			if (save == 1)
			{
				donor[index_donor].setPassword(Password);
			}
			if (save == 2)
			{
				recipient[index_recipient].setPassword(Password);
			}
		}
		else
		{
			cout << "Failed! Please try again!\n\n";
			update_data();
		}
	}
	else if (type == "3")
	{
		cout << "Enter The Name :";
		cin >> Name;
		int save = check_password();
		if (save == 1 || save == 2)
		{
			if (save == 1)
			{
				donor[index_donor].setName(Name);
			}
			if ( save == 2)
			{
				recipient[index_recipient].setName(Name);
			}
		}
		else
		{
			cout << "Failed! Please try again!\n\n";
			update_data();
		}
	}
	else if (type == "4")
	{
		cout << "Enter The  Age :";
		cin >> Age;
		int save = check_password();
		if (save == 1 || save == 2)
		{
			if (save == 1)
			{
				donor[index_donor].setAge(Age);
			}
			if (save == 2)
			{
				recipient[index_recipient].setAge(Age);
			}
		}
		else
		{
			cout << "Failed! Please try again!\n\n";
			update_data();
		}
	}
	else if (type == "5")
	{
		cout << "Enter The Mail :";
		cin >> Mail;
		int save = check_password();
		if (save == 1 || save == 2)
		{
			if ( save == 1)
			{
				donor[index_donor].setMail(Mail);
			}
			if (save == 2)
			{
				recipient[index_recipient].setMail(Mail);
			}
		}
		else
		{
			cout << "Failed! Please try again!\n\n";
			update_data();
		}
	}
	else if (type == "6")
	{
		cout << "Enter The Gender :";
		cin >> Gender;
		int save = check_password();
		if (save == 1 || save == 2)
		{
			if (save == 1)
			{
				donor[index_donor].setGender(Gender);
			}
			if (save == 2)
			{
				recipient[index_recipient].setGender(Gender);
			}
		}
		else
		{
			cout << "Failed! Please try again!\n\n";
			update_data();
		}
	}
	else if (type == "7")
	{
		cout << "Enter The Blood_type :";
		cin >> Blood_type;
		transform(Blood_type.begin(), Blood_type.end(), Blood_type.begin(), ::toupper);
		int save = check_password();
		if (save == 1 || save == 2)
		{
			if (save == 1)
			{
				donor[index_donor].setBlood_type(Blood_type);
			}
			if ( save == 2)
			{
				recipient[index_recipient].setBlood_type(Blood_type);
			}
		}
		else
		{
			cout << "Failed! Please try again!\n\n";
			update_data();
		}
	}
	
}
void request_donation() {
	int press;
	bool check = false;
	Blood_information blood;
	fileDonor FD;
	file_boold BI;
	string date;
	if (donor[index_donor].getAge() < 18 || donor[index_donor].getAge() > 60)
	{
		cout << "You cannot donate blood because your age is not appropriate and blood donation may cause health damage to you\n";
		cout << "***Thank you for your donation at this age***\n\n";
		choose_operation();
	}
	else {
		if (donor[index_donor].getDisease() == "null" && donor[index_donor].getMedicine() == "null")
		{
			cout << "you can donate ,To confirm the donation request, press 1 :";
			cin >> press;
			if (press == 1)
			{
				cout << "Enter today's date : ";
				cin >> date;
				for (int i = 0; i < blood_information.size(); i++)
				{
					if (donor[index_donor].getBlood_type() == blood_information[i].gettype())
					{
						blood_information[i].setQuantity(blood_information[i].getQuantity() + 1);
						blood_information[i].setreceived_date(date);
						cout << "Your donation request has been confirmed, thank you .\n\n";
						check = true;
					}

				}
				if (check == false)
				{
					blood.settype(donor[index_donor].getBlood_type());
					blood.setQuantity(0);
					blood.setreceived_date(date);
					blood.setexpiry_date("30/9/2021");
					blood_information.push_back(blood);
					cout << "Your donation request has been confirmed, thank you .\n\n";

				}
				BI.write(blood_information);
				return_to();
			}
			else 
			{
				cout << "Failed! Please try again!\n";
				choose_operation();
			}
		}
		else
		{
			cout << "you cannot donate because you have some diseases and blood donation may cause health damage to you \n\n";
			choose_operation();
		}
	}

}

void display_data()
{
	if (choose == "1")
	{
		cout << "***************************************************************************\n";
		cout << "Your Name : " << donor[index_donor].getName()<<endl;
		cout << "Your ID : " << donor[index_donor].getId() << endl;
		cout << "Your Password : " << donor[index_donor].getPassword() << endl;
		cout << "Your Mail : " << donor[index_donor].getMail() << endl;
		cout << "Your Age : " << donor[index_donor].getAge() << endl;
		cout << "Your Gender : " << donor[index_donor].getGender() << endl;
		cout << "Your Blood type : " << donor[index_donor].getBlood_type() << endl;
		cout << "Your Disease : " << donor[index_donor].getDisease() << endl;
		cout << "Your Medicine : " << donor[index_donor].getMedicine() << endl;
		cout << "Your Date : " << donor[index_donor].getDate()<<endl;
		cout << "***************************************************************************\n";

	}
	else
	{
		cout << "***************************************************************************\n";
		cout << "Your Name : " << recipient[index_recipient].getName() << endl;
		cout << "Your ID : " << recipient[index_recipient].getId() << endl;
		cout << "Your Password : " << recipient[index_recipient].getPassword() << endl;
		cout << "Your Mail : " << recipient[index_recipient].getMail() << endl;
		cout << "Your Age : " << recipient[index_recipient].getAge() << endl;
		cout << "Your Gender : " << recipient[index_recipient].getGender() << endl;
		cout << "Your Blood type : " << recipient[index_recipient].getBlood_type() << endl;
		cout << "Your Hospital : " << recipient[index_recipient].getHospital() << endl;
		cout << "Your Doctor : " << recipient[index_recipient].getDoctor()<<endl;
		cout << "***************************************************************************\n";

	}
	return_to();
}
void bloodtype_request()
{
	int quantity_w;
	string Blood_w;
	file_boold FB;
	bool check = false;
	string enter;
	string hospital;
	cout << "Enter the blood type that you need :";
	cin >> Blood_w;
	cout << "Enter the blood quantity that you need :";
	cin >> quantity_w;
	for (int i = 0; i < blood_information.size(); i++)
	{
		if (Blood_w == blood_information[i].gettype())
		{
			check = true;
			if (quantity_w < blood_information[i].getQuantity())
			{
				
				cout << "Do you want to send the quantity to your" << recipient[index_recipient].getHospital() << "Hospital ? \n";
				cout << "1-yes\n";
				cout << "2-no\n\n";
				cout << "Enter : ";
				cin >> enter;
				transform(enter.begin(), enter.end(), enter.begin(), ::tolower);
				if (enter == "1" || enter == "yes" )
				{
					cout << "Donation reception is successful\n\n";
					blood_information[i].setQuantity(blood_information[i].getQuantity() - quantity_w);
					FB.write(blood_information);
					return_to();
					break;
				}
				else if (enter == "2" || enter == "no" )
				{
					cout << "Enter the Hospital : ";
					cin >> hospital;
					blood_information[i].setQuantity(blood_information[i].getQuantity() - quantity_w);
					FB.write(blood_information);
					break;
				}
				else
				{
					int count = 3;
					while (count > 0)
					{
						cout << "Faild choose! Try again\n\n";
						bloodtype_request();

					}
					break;
				}
			}
			else if (quantity_w > blood_information[i].getQuantity())
			{

				cout << "There is no such quantity because it is large\n";
				cout << "Please wait until the required quantity is available\n";
				break;
			}
			else
			{
				cout << "There are no quantities of this blood type\n\n";
				break;
			}
		}
	}
	if (check == false)
	{
		cout << "This blood type does not exist\n\n";
	}
	return_to();
}