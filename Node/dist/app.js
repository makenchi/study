"use strict";
var Carro = /** @class */ (function () {
    function Carro(modelo, numDePortas) {
        this.velocidade = 0;
        this.modelo = modelo;
        this.numDePortas = numDePortas;
    }
    Carro.prototype.acelerar = function () {
        this.velocidade = this.velocidade + 10;
    };
    Carro.prototype.parar = function () {
        this.velocidade = 0;
    };
    Carro.prototype.mostraVelocidade = function () {
        return this.velocidade;
    };
    return Carro;
}());
var carroA = new Carro('Uno', 2);
console.log(carroA);
carroA.acelerar();
console.log(carroA);
carroA.parar();
console.log(carroA);
