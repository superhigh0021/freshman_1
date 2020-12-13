//私有继承都不可访问 
#include<iostream>

class vehicle {
	protected:
		int wheels;
		double weight;
	public:
		void initialize(int whls, double wght);
		int get_wheels() {
			return wheels;
		}
		double get_weight() {
			return weight;
		}
		double wheel_loading() {
			return weight/wheels;
		}
};

class car: public vehicle {
	private:
		int passenger_load;
	public:
		void initialize(int whls, double wght, int people =4);
		int passengers() {
			return passenger_load;
		}
};

class truck: public vehicle {
	private:
		int passenger_load;
		double payload;
	public:
		void init_truck(int number =2, double max_load =24000.0);
		double efficiency();
		int passengers() {
			return passenger_load;
		}
};

void vehicle::initialize(int whls, double wght) {
	wheels=whls;
	weight=wght;
}

void car::initialize(int whls, double wght, int people) {
	wheels=whls;
	weight=wght;
	passenger_load=people;
}

void truck::init_truck(int number, double max_load) {
	passenger_load=number;
	payload=max_load;
}

double truck::efficiency() {
	return payload/(payload+weight);
}

int main() {
	vehicle bicycle;
	bicycle.initialize(2,25);
	std::cout<<"the bicycle has "<<bicycle.get_wheels()<<" wheels.\n";
	std::cout<<"the bicycle weighs "<<bicycle.get_weight()<<" pounds.\n";
	std::cout<<"the bicycle's wheel loading is "<<bicycle.wheel_loading()<<" pounds per tire.\n\n";

	car audi;
	audi.initialize(4,3500.0,5);
	std::cout<<"the audi has "<<audi.get_wheels()<<" wheels.\n";
	std::cout<<"the audi weighs "<<audi.get_weight()<<" pounds.\n";
	std::cout<<"the audi's wheel loading is "<<audi.wheel_loading()<<" pounds per tire.\n\n";

	truck jief;
	jief.initialize(18,12500.0);
	jief.init_truck(2,33675.0);
	std::cout<<"the jief has "<<jief.get_wheels()<<" wheels.\n";
	std::cout<<"the jief weighs "<<jief.get_weight()<<" pounds.\n";
	std::cout<<"the jief's efficiency is "<<100.0*jief.efficiency()<<" percent.\n";
}
