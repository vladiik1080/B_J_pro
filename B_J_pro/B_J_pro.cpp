#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Card
{
public:
	enum rank 
	{
		ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
	};
	enum suit
	{
		CLUBS, DIAMONDS, HEARTS, SPADES
	};
	Card(rank r = ACE, suit s = SPADES, bool ifu = true);
	int getValue() const;
	void Flip();
private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};

Card::Card(rank Rank, suit Suit, bool IsFaceUp)
{
	m_Rank = Rank;
	m_Suit = Suit;
	m_IsFaceUp = IsFaceUp;
}

int Card::getValue() const
{
	int value = 0;
	if (m_IsFaceUp)
	{
		value = m_Rank;
		if (value > 10)
		{
			value = 10;
		}
	}
	return value;
}

void Card::Flip()
{
	m_IsFaceUp = !(m_IsFaceUp);
}

class Hand
{
public:
	Hand();
	virtual ~Hand();
	void Add(Card* pCard);
	void Clear();
	int getTotal() const;

private:
	vector <Card*> m_Cards;
};

Hand::Hand()
{
	m_Cards.reserve(7);
}

Hand::~Hand()
{
	Clear();
}

void Hand::Add(Card* pCard)
{
	m_Cards.push_back(pCard);
}

void Hand::Clear()
{
	vector<Card*>::iterator iter = m_Cards.begin();
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		delete* iter;
		*iter = 0;
	}
	m_Cards.clear();
}

int Hand::getTotal() const
{
	if (m_Cards.empty()) return 0;

	if (m_Cards[0]->getValue() == 0)
	{
		return 0;
	}
	int total = 0;
	vector<Card*>::const_iterator iter;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		total += (*iter)->getValue();
	}
	bool containsAce = false;
	for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
	{
		if ((*iter)->getValue() == Card::ACE)
		{
			containsAce = true;
		}
	}
	if (containsAce && total <= 11)
	{
		total += 10;
	}
	return total;
}

class Deck :public Hand
{
public:


private:

};

class GenericPlayer :public Hand
{
public:


private:

};

class Player :public GenericPlayer
{
public:


private:

};

class House :public GenericPlayer
{
public:


private:

};

class Game
{
public:


private:

};

int main()
{
	return 0;
}



