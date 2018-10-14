"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var Concesionaria = /** @class */ (function () {
    function Concesionaria(endereco, listaCarros) {
        this.endereco = endereco;
        this.listaDeCarros = listaCarros;
    }
    Concesionaria.prototype.fornecerEndereco = function () {
        return this.endereco;
    };
    Concesionaria.prototype.mostrarListaDeCarros = function () {
        return this.listaDeCarros;
    };
    Concesionaria.prototype.fornecerHoraDeFunc = function () {
        return 'De segunda a sexta das 08:00 as 19:00 e sábados das 09:00 as 14:00';
    };
    return Concesionaria;
}());
exports.Concesionaria = Concesionaria;
