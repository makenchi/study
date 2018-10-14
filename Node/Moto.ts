import {Veiculo} from './Veiculo'

export class Moto extends Veiculo{
    constructor(modelo: string){
        super()
        this.modelo = modelo        
    }
    
    public acelerar(): void{
        this.velocidade = this.velocidade + 20
    }
}