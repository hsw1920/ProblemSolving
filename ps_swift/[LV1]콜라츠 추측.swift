func go(_ a:Int, _ cnt: Int) -> Int{
    if cnt>=500{
        return -1
    }
    if a==1{
        return cnt
    }
    if a%2==0 {
        return go(a/2,cnt+1)
    }
    else {
        return go(a*3+1,cnt+1)
    }
}
func solution(_ num:Int) -> Int {
    return go(num,0)    
}