#pragma once
#include "Id.h"
#include "Token.h"
#include <unordered_map>

class Env
{
private:
	unordered_map<Token*, Id*> *table;
protected:
	Env* prev;
public:
	Env();
	Env(Env*);
	void put(Token*, Id*);
	Id* get(Token*);
};
Env::Env()
{
	table = new unordered_map<Token*, Id*>;
	prev = NULL;
}

Env::Env(Env* e)
{
	table = new unordered_map<Token*, Id*>;
	prev = e;
}

void Env::put(Token* t, Id* id)
{
	table->insert({ t, id });
}

Id* Env::get(Token* t)
{
	for (auto it = table->begin(); it != table->end(); ++it)
	{
		if (it->first == t)
			return it->second;
	}
	return NULL;
}