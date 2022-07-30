func solution(_ n:Int64) -> [Int] {
    var res : [Int] = []
    var k = n
    while(true){
        res.append(Int(k%10))
        k /= 10
        if k == 0 {
            break;
        }
    }
    return res
}