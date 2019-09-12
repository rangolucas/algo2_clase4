#include "SistemaDeMensajes.h"

//Ejercicio 1
SistemaDeMensajes::SistemaDeMensajes() {
    for (int i = 0; i < 4; ++i) {
        _conns[i] = nullptr;
        _proxies[i] = nullptr;
    }
}

void SistemaDeMensajes::registrarJugador(int id, string ip) {
    if(registrado(id)) desregistrarJugador(id); //Ejercicio 3 b)
    _conns[id] = new ConexionJugador(ip);
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {
    _conns[id]->enviarMensaje(mensaje);
}

bool SistemaDeMensajes::registrado(int id) const {
    return _conns[id] != nullptr;
}

string SistemaDeMensajes::ipJugador(int id) const {
    return _conns[id]->ip();
}

//Ejercicio 2
SistemaDeMensajes::~SistemaDeMensajes() {
    for (int i = 0; i < 4; ++i) {
        delete _conns[i];
        if(_proxies[i] != nullptr) delete _proxies[i]; //Ejercicio 5
    }
}

//Ejercicio 3 a)
void SistemaDeMensajes::desregistrarJugador(int id) {
    delete _conns[id];
    _conns[id] = nullptr;
}

//Ejercicio 4
//Pre: registrado(id)
//Proxy* SistemaDeMensajes::obtenerProxy(int id) {
//    ConexionJugador *pJugador = _conns[id];
//    delete _proxies[id];
//    Proxy *newProxy = new Proxy(pJugador);
//    _proxies[id] = newProxy;
//    return newProxy;
//}

Proxy* SistemaDeMensajes::obtenerProxy(int id) {
    ConexionJugador *pJugador = _conns[id];
    delete _proxies[id];
    Proxy *newProxy = new Proxy(&pJugador);
    _proxies[id] = newProxy;
    return newProxy;
}




