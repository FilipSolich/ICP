#include "socket.hh"
#include "socketitem.hh"

Socket::Socket(Class *cls, Position position)
{
    this->cls = cls;
    this->position = position;
    this->item = new SocketItem(this);
}
