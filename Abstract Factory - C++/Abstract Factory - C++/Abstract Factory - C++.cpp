#include <iostream>
using namespace std;

__interface IEngine {
	virtual void RealeaseEngine() = 0;
};

class JapaneseEngine : public IEngine {
public:
	virtual void RealeaseEngine() override {
		cout << "Japanese engine\n";
	}
};

class GermanEngine : public IEngine {
public:
	virtual void RealeaseEngine() override {
		cout << "German engine\n";
	}
};

__interface ICar {
	virtual void ReleaseCar(IEngine* engine) = 0;
};

class JapaneseCar : public ICar {
public:
	virtual void ReleaseCar(IEngine* engine) override {
		cout << "Assembled a Japanese automobile:\n";
		engine->RealeaseEngine();
	}
};

class GermanCar : public ICar {
	virtual void ReleaseCar(IEngine* engine) override {
		cout << "Assembled a German automobile:\n";
		engine->RealeaseEngine();
	}
};

__interface IFactory {
	virtual IEngine* CreateEngine() = 0;
	virtual ICar* CreateCar() = 0;
};

class JapaneseFactory : public IFactory {
public:
	virtual IEngine* CreateEngine() override {
		return new JapaneseEngine();
	}

	virtual ICar* CreateCar() override {
		return new JapaneseCar();
	}
};

class GermanFactory : public IFactory {
public:
	virtual IEngine* CreateEngine() override {
		return new GermanEngine();
	}

	virtual ICar* CreateCar() override {
		return new GermanCar();
	}
};

int main() {
	IFactory* jFactory = new JapaneseFactory();
	IEngine* jEngine = jFactory->CreateEngine();
	ICar* jCar = jFactory->CreateCar();
	jCar->ReleaseCar(jEngine);

	IFactory* gFactory = new GermanFactory();
	IEngine* gEngine = gFactory->CreateEngine();
	ICar* gCar = gFactory->CreateCar();
	gCar->ReleaseCar(gEngine);
}