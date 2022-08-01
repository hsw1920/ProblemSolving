import Foundation

func solution(_ price:Int, _ money:Int, _ count:Int) -> Int64{
    var k = (count+1)*count/2
    if money > k*price {
        return 0
    }
    return Int64(k*price-money)
}