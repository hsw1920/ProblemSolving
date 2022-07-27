func solution(_ x:Int, _ n:Int) -> [Int64] {
    //x부터 n까지 증가하는 n개의 리스트
    return (1...n).lazy.map{Int64(x)*Int64($0)}
    // 시퀀스 + 고차함수이용
}