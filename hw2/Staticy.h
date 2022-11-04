#ifndef STATICY_H_
#define STATICY_H_

#include <string>

class Staticy {
private:
	static int count;

private:
	Staticy(int i);

public:
	static Staticy* makeStaticy(int i);
	static int getEvenCount();

};
#endif /* ADDRESS_H_ */
