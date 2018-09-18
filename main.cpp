#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

const int len = 30, strings = 100;
char mass[len][strings];
const char ch = '\n';
using namespace std;
int p3 = 99;
string Type[] = {
	"Боевой",
	"Гражданский"
};

string Class[] = {
	"Линкор",
	"Крейсер",
	"Подлодка",
	"Параход"
};
string Special[]{
	"True",
	"False"
};
string Size[]{
	"120x50x130",
	"150x70x170",
	"200x40x100"
};
string Area[] = {
	"Квадрат А5",
	"Квадрат Б6",
	"Квадрат т8",
	"Залив"
};
string TypeEnergy[] = {
	"Дизельная",
	"Ядерная",
	"Паротурбинная"
};
string Displacement[] = {
	"100л",
	"150л",
	"200л",
	"250л"
};
string Capacity[] = {
	"500л",
	"600л",
	"1000л",
	"1100л"
};
string Crew[] = {
	"100человек",
	"200человек",
	"300человек"
};
string Passengers[] = {
	"100",
	"200",
	"500"
};
string Speed[] = {
	"10узлов",
	"15узлов",
	"20узлов"
};

class IShip
{
public:
	virtual void info() = 0;

};

class Ship : public IShip
{
public:

	virtual void info()
	{
		std::cout << "Ship" << std::endl;
	}
};
//AbstractProduct
class IType
{

public:
	int type;
	virtual string getType(int) = 0;

};

class IClass
{
public:
	int clas;
	virtual string getClass(int) = 0;

};

class ISpecial
{
public:
	int special;
	virtual string getSpecial(int) = 0;

};
class ISize
{

public:
	int size;
	virtual string getSize(int) = 0;

};

class IArea
{
public:
	int area;
	virtual string getArea(int) = 0;

};

class ITypeEnergy
{
public:
	int TE;
	virtual string getTypeEnergy(int) = 0;

};
class IDisplacement
{

public:
	int dis;
	virtual string getDisplacement(int) = 0;

};

class ICapacity
{
public:
	int capacity;
	virtual string getCapacity(int) = 0;

};

class ICrew
{
public:
	int crew;
	virtual string getCrew(int) = 0;

};

class IPassengers
{
public:
	int pass;
	virtual string getPassengers(int) = 0;

};
class ISpeed
{
public:
	int speed;
	virtual string getSpeed(int) = 0;

};


//ConctreteProduct
class ShipType : public IType
{
public:
	virtual string getType(int type)
	{
		this->type = type;
		return Type[type];
	}
};

class ShipClass : public IClass
{
public:
	virtual string getClass(int clas)
	{
		this->clas = clas;
		return Class[clas];
	}
};

class ShipSpecial : public ISpecial
{
public:
	virtual string getSpecial(int special)
	{
		this->special = special;
		return Special[special];
	}
};
class ShipSize : public ISize
{
public:
	virtual string getSize(int size)
	{
		this->size = size;
		return Size[size];
	}
};

class ShipArea : public IArea
{
public:
	virtual string getArea(int area)
	{
		this->area = area;
		return Area[area];
	}
};

class ShipTypeEnergy : public ITypeEnergy
{
public:
	virtual string getTypeEnergy(int TE)
	{
		this->TE = TE;
		return TypeEnergy[TE];
	}
};
class ShipDisplacement : public IDisplacement
{
public:
	virtual string getDisplacement(int dis)
	{
		this->dis = dis;
		return Displacement[dis];
	}
};

class ShipCapacity : public ICapacity
{
public:
	virtual string getCapacity(int capacity)
	{
		this->capacity = capacity;
		return Capacity[capacity];
	}
};

class ShipCrew : public ICrew
{
public:
	virtual string getCrew(int crew)
	{
		this->crew = crew;
		return Crew[crew];
	}
};

class ShipPassengers : public IPassengers
{
public:
	virtual string getPassengers(int pass)
	{
		this->pass = pass;
		return Passengers[pass];
	}
};
class ShipSpeed : public ISpeed
{
public:
	virtual string getSpeed(int speed)
	{
		this->speed = speed;
		return Speed[speed];
	}
};
//AbstractFactory
class AbstractFactory
{

public:
	IShip * getNewShip()
	{
		return createShip();
	}
	IType* getNewType()
	{
		return createType();
	}
	IClass* getNewClass()
	{
		return createClass();
	}
	ISpecial* getNewSpecial()
	{
		return createSpecial();
	}
	ISize* getNewSize()
	{
		return createSize();
	}
	IArea* getNewArea()
	{
		return createArea();
	}
	ITypeEnergy* getNewTypeEnergy()
	{
		return createTypeEnergy();
	}
	IDisplacement* getNewDisplacement()
	{
		return createDisplacement();
	}
	ICapacity* getNewCapacity()
	{
		return createCapacity();
	}
	ICrew* getNewCrew()
	{
		return createCrew();
	}
	IPassengers* getNewPassengers()
	{
		return createPassengers();
	}ISpeed* getNewSpeed()
	{
		return createSpeed();
	}
	virtual ~AbstractFactory() = default;
protected:
	virtual IShip* createShip() = 0;
	virtual IType* createType() = 0;
	virtual IClass* createClass() = 0;
	virtual ISpecial* createSpecial() = 0;
	virtual ISize* createSize() = 0;
	virtual IArea* createArea() = 0;
	virtual ITypeEnergy* createTypeEnergy() = 0;
	virtual IDisplacement* createDisplacement() = 0;
	virtual ICapacity* createCapacity() = 0;
	virtual ICrew* createCrew() = 0;
	virtual IPassengers* createPassengers() = 0;
	virtual ISpeed* createSpeed() = 0;
};

class ShipFactory : public AbstractFactory
{
protected:
	virtual IShip* createShip()
	{
		return new Ship();
	}
	virtual IType* createType()
	{
		return new ShipType();
	}
	virtual IClass* createClass()
	{
		return new ShipClass();
	}
	virtual ISpecial* createSpecial()
	{
		return new ShipSpecial();
	}
	virtual ISize* createSize()
	{
		return new ShipSize();
	}
	virtual IArea* createArea()
	{
		return new ShipArea();
	}
	virtual ITypeEnergy* createTypeEnergy()
	{
		return new ShipTypeEnergy();
	}
	virtual IDisplacement* createDisplacement()
	{
		return new ShipDisplacement();
	}
	virtual ICapacity* createCapacity()
	{
		return new ShipCapacity();
	}
	virtual ICrew* createCrew()
	{
		return new ShipCrew();
	}
	virtual IPassengers* createPassengers()
	{
		return new ShipPassengers();
	}
	virtual ISpeed* createSpeed()
	{
		return new ShipSpeed();
	}

};

int main()
{
	setlocale(LC_ALL, "RUS");
	AbstractFactory* factory = NULL;


	ISize* size = NULL;
	IDisplacement* dis = NULL;
	ICapacity* capacity = NULL;
	ISpeed* speed = NULL;
	IArea* area = NULL;
	IPassengers* pass = NULL;
	ITypeEnergy* typEn = NULL;
	IClass* clas = NULL;
	IType* type = NULL;
	ICrew* crew = NULL;
	ISpecial** special = NULL;
	while (1)
	{
		std::cout << "0 - Ввести новый флот" << endl
			<< "1 - Считать флот из файла" << endl
			<< "2 - Выход" << endl;
		int p1;
		std::cin >> p1;
		switch (p1)
		{
		case 0:
		{
			std::cout << "Введите кол-во кораблей" << endl;
			int kol;
			std::cin >> kol;
			ShipFactory*  test = new ShipFactory[kol];
			special = new ISpecial*[kol];

			factory = test;
			std::cout << "Введите имя флота" << endl;
			string name;
			std::cin >> name;
			for (int i = 0; i < kol; i++) {
				special[i] = factory[i].getNewSpecial();
				special[i]->getSpecial(1);
			}

			std::cout << "Выберите Тип" << endl;
			for (int i = 0; i <2; i++)
				std::cout << i << " " << Type[i] << endl;
			int p = 0;
			std::cin >> p;
			for (int i = 0; i < kol; i++)
			{
				type = factory[i].getNewType();
				type->getType(p);
			}
			std::cout << "Выбрано " << type->getType(p) << endl;

			std::cout << "Выберите класс" << endl;
			for (int i = 0; i < 4; i++)
				std::cout << i << " " << Class[i] << endl;
			std::cin >> p;
			for (int i = 0; i < kol; i++) {
				clas = factory[i].getNewClass();
				clas->getClass(p);
			}
			std::cout << "Выбрано " << clas->getClass(p) << endl;

			std::cout << "Нужен корабль спец наз? " << endl << "3) YES 4) NO" << endl;
			int p2;
			std::cin >> p2;
			switch (p2) {
			case 3: {std::cout << "Введите номер корабля" << endl;
				std::cin >> p3;
				special[p3] = factory[p3].getNewSpecial();
				std::cout << "Выбрано " << special[p3]->getSpecial(0) << endl;
				break; }
			case 4: {
				break; }
			}
			std::cout << "Выберите габариты" << endl;
			for (int i = 0; i < 3; i++)
				std::cout << i << " " << Size[i] << endl;
			std::cin >> p;
			for (int i = 0; i < kol; i++) {
				size = factory[i].getNewSize();
				size->getSize(p);
			}
			std::cout << "Выбрано " << size->getSize(p) << endl;

			std::cout << "Выберите район плавания" << endl;
			for (int i = 0; i < 4; i++)
				std::cout << i << " " << Area[i] << endl;
			std::cin >> p;
			for (int i = 0; i < kol; i++) {
				area = factory[i].getNewArea();
				area->getArea(p);
			}
			std::cout << "Выбрано " << area->getArea(p) << endl;

			std::cout << "Выберите Тип энергии" << endl;
			for (int i = 0; i < 3; i++)
				std::cout << i << " " << TypeEnergy[i] << endl;
			std::cin >> p;
			for (int i = 0; i < kol; i++) {
				typEn = factory[i].getNewTypeEnergy();
				typEn->getTypeEnergy(p);
			}
			std::cout << "Выбрано " << typEn->getTypeEnergy(p) << endl;

			std::cout << "Выберите водоизмещение" << endl;
			for (int i = 0; i <4; i++)
				std::cout << i << " " << Displacement[i] << endl;
			std::cin >> p;
			for (int i = 0; i < kol; i++) {
				dis = factory[i].getNewDisplacement();
				dis->getDisplacement(p);
			}
			std::cout << "Выбрано " << dis->getDisplacement(p) << endl;

			std::cout << "Выберите вместимость" << endl;
			for (int i = 0; i < 4; i++)
				std::cout << i << " " << Capacity[i] << endl;
			std::cin >> p;
			for (int i = 0; i < kol; i++) {
				capacity = factory[i].getNewCapacity();
				capacity->getCapacity(p);
			}
			std::cout << "Выбрано " << capacity->getCapacity(p) << endl;

			std::cout << "Выберите кол-во экипажа" << endl;
			for (int i = 0; i <3; i++)
				std::cout << i << " " << Crew[i] << endl;
			std::cin >> p;
			for (int i = 0; i < kol; i++) {
				crew = factory[i].getNewCrew();
				crew->getCrew(p);
			}
			std::cout << "Выбрано " << crew->getCrew(p) << endl;

			std::cout << "Выберите кол-во пассажиров" << endl;
			for (int i = 0; i < 3; i++)
				std::cout << i << " " << Passengers[i] << endl;
			std::cin >> p;
			for (int i = 0; i < kol; i++) {
				pass = factory[i].getNewPassengers();
				pass->getPassengers(p);
			}
			std::cout << "Выбрано " << pass->getPassengers(p) << endl;

			std::cout << "Выберите скорость" << endl;
			for (int i = 0; i < 3; i++)
				std::cout << i << " " << Speed[i] << endl;
			std::cin >> p;
			for (int i = 0; i < kol; i++) {
				speed = factory[i].getNewSpeed();
				speed->getSpeed(p);
			}
			std::cout << "Выбрано " << speed->getSpeed(p) << endl;

			fstream f(name + ".txt", ios::out);
			for (int i = 0; i < kol; i++) {

				f << type->getType(type->type) << endl
					<< clas->getClass(clas->clas) << endl
					<< special[i]->getSpecial(special[i]->special) << endl
					<< size->getSize(size->size) << endl
					<< area->getArea(area->area) << endl
					<< typEn->getTypeEnergy(typEn->TE) << endl
					<< dis->getDisplacement(dis->dis) << endl
					<< capacity->getCapacity(capacity->capacity) << endl
					<< crew->getCrew(crew->crew) << endl
					<< pass->getPassengers(pass->pass) << endl
					<< speed->getSpeed(speed->speed) << endl;


			}

			break;
		}
		case 1:
		{
			std::cout << "введите имя файла" << endl;
			string file;
			std::cin >> file;
			ifstream shread(file + ".txt", ios::in | ios::binary);
			if (!shread) return 1;
			for (int r = 0; !shread.eof(); r++)
			{
				shread.getline(mass[r], len - 1, ch);
				std::cout << "OUT" << r + 1 << "=" << mass[r] << endl;
			}
			shread.close();


		}
		break;
		case 2:
			exit(NULL);
			break;
		}

	}
}
