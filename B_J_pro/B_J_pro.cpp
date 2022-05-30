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

private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
	Card(rank Rank, suit Suit, bool IsFaceUp);
	int getValue() const;
	void Flip();
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


private:

};

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



