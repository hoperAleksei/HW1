/*
 *
1. Реализовать класс Human. Создать несколько объектов класса Human.
2. Добавить несколько свойства (не забывать добавить значимые поля в конструктор)
3. Добавить getter'ы и setter'ы для созданных полей
4. Реализовать дочерний класс к Human. Например, Student, Character и др...
5. Продемонстрировать обращение к свойствам объектов дочерних и родительских классов.
6. Добавить несколько наследников от различных родителей (сделать дерево из минимум из 5 классов)
7. Поэкспериментировать с множественным наследованием

(По сути пройтись по всем 8-ми пунктам, о которых говорили на паре)
 *
 *
 *
 *
 * */


#include <iostream>
#include <string>

using namespace std;


class Human
{
private:
	int height;
	int weight;
	string gender;
public:
	Human(int height, int weight, string gender): height(height), weight(weight), gender(move(gender)){}
	
	int getHeight()
	{
		return height;
	}
	
	int getWeight()
	{
		return weight;
	}
	
	string getGender()
	{
		return gender;
	}
	
	void setHeight(int h)
	{
		height = h;
	}
	
	void setWeight(int w)
	{
		weight = w;
	}
	
	void setGender(string g)
	{
		gender = move(g);
	}
};

class Worker: public Human
{
private:
	string profession;
public:
	Worker(int height, int weight, string gender, string profession): Human(height, weight, move(gender)), profession(
			move(profession)){}
	string getProfession()
	{
		return profession;
	}
	
	void setProfession(string p)
	{
		profession = move(p);
	}
	
	void work()
	{
		cout << "Work as a " <<  profession << ": " << endl;
		for (int i = 0; i < 100; ++i)
		{
			cout << "work" << endl;
		}
	}
};

class Student: public Human
{
private:
	string course;
public:
	string getCourse()
	{
		return course;
	}
	
	void setCourse(string c)
	{
		course = move(c);
	}
	
	void study()
	{
		cout << "Study in a " <<  course << " course: " << endl;
		for (int i = 0; i < 100; ++i)
		{
			cout << "study" << endl;
		}
	}
	
	Student(int height, int weight, string gender, string course): Human(height, weight, move(gender)), course(
			move(course)){};
};

class LazyWorker: public Worker
{
public:
	void work()
	{
		cout << "No no no";
	}
	
	LazyWorker(int height, int weight, string gender, string profession): Worker(height, weight, gender, profession){};
	
};

class LazyStudent: public Student
{
public:
	void study()
	{
		cout << "No no no";
	}
	
	LazyStudent(int height, int weight, string gender, string course): Student(height, weight, gender, course){};
	
};

class bird
{
public:
	void fly()
	{
		cout << "fly fly fly" << endl;
	}
	
};

class jasdklf: public LazyWorker, public bird
{
public:
	jasdklf(int height, int weight, string gender, string profession): LazyWorker(height, weight, gender, profession){}
};

int main()
{
	Human h1 = Human(150, 150, "male");
	Human h2 = Human(150, 150, "female");
	
	Worker w1 = Worker(150, 150, "male", "teacher");
	Worker w2 = Worker(150, 150, "female", "actor");
	
	Student s1 = Student(150, 150, "male", "PE");
	Student s2 = Student(150, 150, "female", "PE");
	
	LazyWorker lw = LazyWorker(150, 150, "male", "teacher");
	
	LazyStudent ls = LazyStudent(150, 150, "male", "PE");
	
	jasdklf qwerty = jasdklf(150, 150, "male", "teacher");
	
	qwerty.fly();
	qwerty.work();
	cout << qwerty.getProfession();
	cout << qwerty.getHeight();
	
	ls.study();
	lw.work();
	
	w1.work();
	s1.study();
	
	cout << h1.getGender();
}

