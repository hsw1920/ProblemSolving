func solution(_ x:Int) -> Bool {
    var sum = 0
    var k = x
    var u = k
    while(true){
        if k == 0 {
            break
        }
        sum += k%10
        k /= 10
    }
    if u%sum == 0 {
        return true
    }
    return false
}