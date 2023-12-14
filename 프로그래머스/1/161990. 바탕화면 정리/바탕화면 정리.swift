import Foundation

func solution(_ wallpaper:[String]) -> [Int] {
    var mnx: Int = 51
    var mny: Int = 51
    var mxx: Int = 0
    var mxy: Int = 0
    for (i,item) in wallpaper.enumerated() {
        for (j,it) in item.enumerated() {
            if it=="#"{
                mnx = min(mnx,i)
                mny = min(mny,j)
                mxx = max(mxx,i+1)
                mxy = max(mxy,j+1)
            }
        }
    }
    
    return [mnx,mny,mxx,mxy]
}