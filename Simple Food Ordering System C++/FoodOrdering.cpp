#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <windows.h>
using namespace std;

double calTot(double qty, double price){
	return qty * price;
}

int strToInt(char stringTxt[]){

	char *endptr;
	long value = strtol(stringTxt, &endptr, 10);
	
	if (endptr == stringTxt){
	    return 0;
	}
	else if (*endptr != '\0'){
	   return 0;
	}
	else{
		return value;
	}
}

int main(){
	int totFood = 8, totDrink = 6, itemNo, i,totItem, qty;
	char user[30],itemNoStr[100], qtyStr[100],needDrink[5];
	double discount = 2, total = 0;
	totItem = totDrink + totFood;	
	/* Store Foods & Drinks*/
	string foods[2][8] = {{"Pizza\t\t","Pasta\t\t","Noodles\t\t","Rice\t\t","Koththu\t\t","Burger\t\t","Shawarma\t\t","Submarine\t\t"}, {"Coca Cola\t\t","Sprite\t\t","Cream Soda\t\t","Fruit Juice\t\t","Tea\t\t\t","Coffee\t\t"}};
	/* Store Foods & Drinks Price*/
	double food_prices[2][8] = {{700, 400, 300, 350, 400, 250, 200, 200}, {150, 120, 130, 200, 60, 80}};
	
	int food_qty[2][8] = {{0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}};
	
	cout<<endl;
	
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h,0xB);


	SetConsoleTextAttribute(h,0xE);
	
	/*Display Menu*/
	cout<<"\t\t\t\t%%%%%%%%%%%%%%%% MENU %%%%%%%%%%%%%%%%%" << endl<<endl;
	
	cout<<"\t\t\t\t-----------------Foods-----------------" << endl;
	
	SetConsoleTextAttribute(h,0xF);
	
	for(i = 0; i < totFood; i++){
		std::cout << std::fixed << std::setprecision(2) <<"\t\t\t\t"<< (i+1) << " : " << foods[0][i] << " - LKR. " << food_prices[0][i] << endl;
	}
	SetConsoleTextAttribute(h,0xE);
	
	cout << endl << "\t\t\t\t-----------------Drinks-----------------" << endl;	
	
	SetConsoleTextAttribute(h,0xF);
	
	for(i = 0; i < totDrink; i++){
		std::cout << std::fixed << std::setprecision(2) <<"\t\t\t\t"<< (i+1) << " : " << foods[1][i] << " - LKR. " << food_prices[1][i] << endl;
	}
	SetConsoleTextAttribute(h,0xE);
	cout<<"\n\n\t\t\t\t---------------Order Now----------------"<<endl<<endl;
	
	SetConsoleTextAttribute(h,0xF);
	
	cout << "\t\t\t\tPlease Enter Your Name\t\t:";
	cin.getline (user, 30);
	cout<<endl;
	
	cout<<"\t\t\t\tHello "<<user<<"...!"<<endl;
	cout<<"\t\t\t\tWelcome to Cafe 99 Chicken Hut,\n\t\t\t\tPlease select your order..."<<endl<<endl;
	SetConsoleTextAttribute(h,0x4);
	cout << "\t\t\t\t(Note: Enter Value Less Than \n\t\t\t\t 0 To Stop Ordering Items.)"<<endl<<endl;
	SetConsoleTextAttribute(h,0xF);
	cout<<"\t\t\t\tEnter Food Item No\t\t:";
	cin.getline (itemNoStr, 100);
	itemNo = strToInt(itemNoStr);
	cin.clear();
	
	while(itemNo >= 0){
		if(itemNo > 0 && itemNo <= totFood){
			cout << "\t\t\t\tHow Many " << foods[0][itemNo-1] << "\n\t\t\t\t\tyou want\t\t:";
			
			cin.getline (qtyStr, 100);
			cin.clear();
			qty = strToInt(qtyStr);
			
			if(qty <= 0){
			SetConsoleTextAttribute(h,0x4);		
				cout << "\t\t\t\tEnter Valid Quantity Amount\n";
			SetConsoleTextAttribute(h,0xF);	
				cout << "\t\t\t\tHow Many " << foods[0][itemNo-1] << "\n\t\t\t\t\tyou want\t\t:";
				cin.getline (qtyStr, 100);
				cin.clear();
				qty = strToInt(qtyStr);	
			}		
			food_qty[0][itemNo-1] += qty;
			total += calTot(qty, food_prices[0][itemNo-1]);
		}else{
		SetConsoleTextAttribute(h,0x4);		
			cout << "\t\t\t\tEntered Item Is Invalid.\n\t\t\t\tPlease Enter Valid Item No Which Is Shown Above..!\n";
		}
		SetConsoleTextAttribute(h,0xF);	
		cout << "\t\t\t\tEnter Food Item No\t\t:";
		cin.getline (itemNoStr, 100);
		cin.clear();
		itemNo = strToInt(itemNoStr);
	}
	
	cout << "\n\t\t\t\tDo You Need A Drink? (Y/N)\t:";
	cin.getline(needDrink, 5);
	string drinkNeed = needDrink;
	cin.clear();
	
	if(drinkNeed == "y" || drinkNeed == "Y"){
		cout << "\n\t\t\t\tEnter Drink Item No\t\t:";
		cin.getline (itemNoStr, 100);
		itemNo = strToInt(itemNoStr);
		cin.clear();
		
		while(itemNo >= 0){
			if((itemNo > 0) && (itemNo <= totDrink)){
				cout << "\t\t\t\tHow Many " << foods[1] [itemNo-1] << "\n\t\t\t\t\tyou want\t\t:";
				
				cin.getline (qtyStr, 100);
				cin.clear();
				qty = strToInt(qtyStr);
				
				if(qty <= 0){
				SetConsoleTextAttribute(h,0x4);			
					cout << "\t\t\t\tEnter Valid Quantity Amount\n";
				SetConsoleTextAttribute(h,0xF);	
					cout << "\t\t\t\tHow Many " << foods[1][itemNo-1] << "\n\t\t\t\t\tyou want\t\t:";
					cin.getline (qtyStr, 100);
					cin.clear();
					qty = strToInt(qtyStr);	
				}
				
				food_qty[1][itemNo-1] += qty;	
				total += calTot(qty, food_prices[0][itemNo-1]);
			}else{
			SetConsoleTextAttribute(h,0x4);	
				cout << "\t\t\t\tEntered Item Is Invalid.\n\t\t\t\tPlease Enter Valid Item No Which Is Shown Above..!\n";
			}
			SetConsoleTextAttribute(h,0xF);
			cout << "\t\t\t\tEnter Drink Item No\t\t:";
			cin.getline (itemNoStr, 100);
			cin.clear();
			itemNo = strToInt(itemNoStr);
		}
	}
	
	double dis_tot;
	dis_tot= total * (discount/100);
	
	/*Purchased Foods & Drinks*/
	
	SetConsoleTextAttribute(h,0xE);
	cout << "\n\t\t\t\t--------Ordered Foods And Drinks--------\n" << endl;
	SetConsoleTextAttribute(h,0xF);
	for(i = 0; i < totFood; i++){
		if(food_qty[0][i] > 0){
			cout <<"\t\t\t\t"<< (i+1) << " : " << foods[0][i] << " \t- " << food_qty[0][i] << endl;
		}
	}
	
	for(i = 0; i < totDrink; i++){
		if(food_qty[1][i] > 0){
			cout <<"\t\t\t\t"<< (i+1) << " : " << foods[1][i] << " \t- " << food_qty[1][i] << endl;
		}
	}
	SetConsoleTextAttribute(h,0xE);
	cout << "\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
	SetConsoleTextAttribute(h,0xF);	
	cout << "\n\t\t\t\tCustomer name\t\t\t :" << user << endl;
	
	cout << "\t\t\t\t----------------------------------------" << endl;
	
	std::cout << std::fixed << std::setprecision(2) << "\t\t\t\tTotal Bill\t\t\t :" << total << endl;	
	
	cout << "\t\t\t\t----------------------------------------" << endl;
	
	std::cout << std::fixed << std::setprecision(2) << "\t\t\t\tDiscount\t\t\t :" << dis_tot << endl;
	
	cout << "\t\t\t\t----------------------------------------" << endl;
	
	SetConsoleTextAttribute(h,0x4);
	cout << "\t\t\t\tGrand Total\t\t\t :" << (total - dis_tot) << endl;
  	
	SetConsoleTextAttribute(h,0xF);
	cout<< "\n\t\t\t\t========================================\n" << endl;
	
	SetConsoleTextAttribute(h,0xE);
	time_t tt;
	struct tm*ti;
	time(&tt);
	ti=localtime(&tt);
	cout<<"\t\t\t\tBill closed time : "<<asctime(ti)<<endl;
	cout<<"\t\t\t\tThank You for ordering..!!"<<endl<<endl;
	cout<< "\n\t\t\t\t		 ******			\n" << endl;	
	
	
	
cout<<endl<<endl;	
}