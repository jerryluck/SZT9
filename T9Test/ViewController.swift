//
//  ViewController.swift
//  T9Test
//
//  Created by 刘彦直 on 2019/8/7.
//  Copyright © 2019 刘彦直. All rights reserved.
//

import UIKit
import SZT9

class ViewController: UIViewController {

    let searcher = T9Searcher()!
    
    override func viewDidLoad() {
        super.viewDidLoad()
    
        searcher.addNode(1, name: "刘彦直", number: ["18680902390"], weight1: 1, weight2: 1)
        
        let names = NSMutableArray()
        let phones = NSMutableArray()
        
        
        searcher.search(withT9: "599", search: nil, nameMatch: names, numberMatch: phones)
        
        for name in names {
            print(name)
        }
        
        for phone in phones {
            print(phone)
        }
        
        let hzPos = NSMutableArray()
        searcher.getPinYin(1, orginStr: "刘彦直", matchPosHZ: hzPos)
    }
}

