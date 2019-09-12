#include "Proxy2.h"

//Ejercicio 6
Proxy::Proxy(ConexionJugador **conn) {
    _conn = conn;
}

void Proxy::enviarMensaje(string msg) {
    (**_conn).enviarMensaje(msg);
}
