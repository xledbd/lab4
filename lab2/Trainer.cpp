#include "Trainer.h"

ostream& operator<<(ostream& out, Trainer& p)
{
	p.printToStream(out);
	return out;
}
