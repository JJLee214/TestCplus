#pragma once

class Singleton
{
	private:
		Singleton() {}
		static Singleton* uniqueInstance;
	public:
		static Singleton* getInstance();
		void showMessage();

};