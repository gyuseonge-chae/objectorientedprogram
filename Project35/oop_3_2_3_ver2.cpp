#include <iostream>
#include <string>

using namespace std;

class item
{
private:
	int price;
	int stock;
	int discount;
public:
	item() {};
	item(int price, int stock) { this->price = price; this->stock = stock;  discount = 0; }
	int getprice() { return price; }
	int getstock() { return stock; }
	int getdiscount() { return discount; }
	void addstock(int num) { this->stock += num; }
	void sell_item(int num) { this->stock -= num; }
	void setdiscount(int num) { discount = num; }
	~item() {};
};

class Pen : public item
{
public:
	Pen() : item(200 * 3, 100)
	{
		cout << "---------Pen--------" << endl << "Price : " << this->getprice() << endl << "Stock : " << this->getstock() << endl << "Discount : " << this->getdiscount() << "%" << endl << "--------------------" << endl;
	}
	void print_pen()
	{
		cout << "---------Pen--------" << endl << "Price : 600" << endl << "Stock : " << this->getstock() << endl << "Discount : " << this->getdiscount() << "%" << endl << "--------------------" << endl;
	}
	~Pen() {};
};

class Pencil : public item
{
public:
	Pencil() : item(100 * 12, 100)
	{
		cout << "------Pencil--------" << endl << "Price : " << this->getprice() << endl << "Stock : " << this->getstock() << endl << "Discount : " << this->getdiscount() << "%" << endl << "--------------------" << endl;
	}
	void print_pencil()
	{
		cout << "------Pencil--------" << endl << "Price : 1200" << endl << "Stock : " << this->getstock() << endl << "Discount : " << this->getdiscount() << "%" << endl << "--------------------" << endl;
	}
	~Pencil() {};
};

class Eraser : public item
{
public:
	Eraser() : item(500, 100)
	{
		cout << "-------Eraser-------" << endl << "Price : " << this->getprice() << endl << "Stock : " << this->getstock() << endl << "Discount : " << this->getdiscount() << "%" << endl << "--------------------" << endl;
	}
	void print_eraser()
	{
		cout << "-------Eraser-------" << endl << "Price : 500" << endl << "Stock : " << this->getstock() << endl << "Discount : " << this->getdiscount() << "%" << endl << "--------------------" << endl;
	}
	~Eraser() {};
};

int main()
{
	int cmd = 10;
	float sales = 0.0;
	Pen pen;
	Pencil pencil;
	Eraser eraser;

	while (1)
	{
		cout << "Enter Any Command() : Sell, 1 : AddStock, 2 : Discount, 3 : Print, 4 : Quit) :";
		cin >> cmd;

		if (cmd == 0)
		{
			char itemName[10] = { 0, };
			int count = 0;
			float temp_sales = 0.0;
			cin >> itemName >> count;

			if (strcmp(itemName, "Pen") == 0)
			{
				if (pen.getstock() < (count * 3))
				{
					pen.sell_item(count * 3);
				}
				double discounts = pen.getdiscount() / 100.0;
				
				temp_sales = 600 * (1 - discounts) * count;
				cout << temp_sales;
				sales += temp_sales;
			}
			else if (strncmp(itemName, "Pencil", 6) == 0)
			{
				float discounts = pencil.getdiscount() / 100.0;

				pencil.sell_item(count * 12);
				temp_sales = 1200 * count * (1 - discounts);
				sales += temp_sales;
			}
			else if (strncmp(itemName, "Eraser", 6) == 0)
			{
				float discounts = eraser.getdiscount() / 100.0;

				eraser.sell_item(count);
				temp_sales = 500 * count * (1 - discounts);
				sales += temp_sales;
			}
		}

		else if (cmd == 1)
		{
			char itemName[10] = { 0, };
			int count = 0;
			int temp_sales = 0;
			cin >> itemName >> count;

			if (strcmp(itemName, "Pen") == 0)
			{
				pen.addstock(count);
			}
			else if (strncmp(itemName, "Pencil", 6) == 0)
			{
				pencil.addstock(count);
			}
			else if (strncmp(itemName, "Eraser", 6) == 0)
			{
				eraser.addstock(count);
			}
		}

		else if (cmd == 2)
		{
			char itemName[10] = { 0, };
			int discount = 0;
			cin >> itemName >> discount;

			if (strcmp(itemName, "Pen") == 0)
			{
				pen.setdiscount(discount);
			}
			else if (strncmp(itemName, "Pencil", 6) == 0)
			{
				pencil.setdiscount(discount);
			}
			else if (strncmp(itemName, "Eraser", 6) == 0)
			{
				eraser.setdiscount(discount);
			}
		}

		else if (cmd == 3)
		{
			pen.print_pen();
			pencil.print_pencil();
			eraser.print_eraser();
		}

		else if (cmd == 4)
		{
			break;
		}

		cout << "====================" << endl << "Sales : " << sales << endl << "====================" << endl;
	}

	return 0;
}