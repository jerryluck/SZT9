//
//  T9Searcher.h
//  SZT9
//
//  Created by 刘彦直 on 2019/8/7.
//  Copyright © 2019 刘彦直. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface T9Searcher : NSObject

+ (instancetype)new NS_UNAVAILABLE;

///@brief 只有指定的包名才能初始化
- (nullable instancetype)init;

#pragma mark - 搜索源

///@brief 添加搜索源
///@param localID 搜索源ID
///@param name 名字
///@param numberArray 号码数组
///@param w1 附加权重1
///@param w2 附加权重2
- (void)addNode:(NSInteger)localID name:(NSString* _Nonnull)name numberArray:(NSArray<NSString*>* _Nonnull)numberArray weight1:(NSInteger)w1 weight2:(NSInteger)w2;

///@brief 替换搜索源
///@param localID 搜索源ID
///@param name 名字
///@param numberArray 号码数组
///@param w1 附加权重1
///@param w2 附加权重2
- (void)replaceNode:(NSInteger)localID name:(NSString*)name numberArray:(NSArray<NSString*>* _Nonnull)numberArray weight1:(NSInteger)w1 weight2:(NSInteger)w2;

///@brief 删除搜索源
///@param localID 搜索源ID
- (void)deleteNode:(NSInteger)localID;

#pragma mark - 搜索
///@brief 无映射搜索联系人,优先姓名匹配，姓名、号码匹配数据不重复
///@param searchText 搜索内容
///@param aSearchedArray 搜索集，不为空就在此内容中搜索，为空搜索全部
///@param nameMatchArray 返回值——搜索后符合姓名匹配的联系人ID数组
///@param numberMatchArray 返回值——搜索后符合号码匹配的联系人ID数组
- (void)search:(NSString* _Nonnull)searchText searchArray:(NSArray<NSNumber*>* _Nullable)aSearchedArray nameMatch:(NSMutableArray<NSString*>* _Nonnull)nameMatchArray numberMatch:(NSMutableArray<NSString*>* _Nonnull)numberMatchArray;

///@brief T9映射搜索联系人,优先姓名匹配，姓名、号码匹配数据不重复
///@param searchText 搜索内容
///@param aSearchedArray 搜索集，不为空就在此内容中搜索，为空搜索全部
///@param nameMatchArray 返回值——搜索后符合姓名匹配的联系人ID数组
///@param numberMatchArray 返回值——搜索后符合号码匹配的联系人ID数组
- (void)searchWithT9:(NSString* _Nonnull)searchText searchArray:(NSArray<NSNumber*>* _Nullable)aSearchedArray nameMatch:(NSMutableArray<NSString*>* _Nonnull)nameMatchArray numberMatch:(NSMutableArray<NSString*>* _Nonnull)numberMatchArray;

///@brief 特定映射搜索联系人,优先姓名匹配，姓名、号码匹配数据不重复
///@param matchFunc 输入与26个字母对应字符的串，比如T9键盘为22233344455566677778889999
///@param searchText 搜索内容
///@param aSearchedArray 搜索集，不为空就在此内容中搜索，为空搜索全部
///@param nameMatchArray 返回值——搜索后符合姓名匹配的联系人ID数组
///@param numberMatchArray 返回值——搜索后符合号码匹配的联系人ID数组
- (void)searchWithFunc:(NSString* _Nonnull)matchFunc searchText:(NSString* _Nonnull)searchText searchArray:(NSArray<NSNumber*>* _Nullable)aSearchedArray nameMatch:(NSMutableArray<NSString*>* _Nonnull)nameMatchArray numberMatch:(NSMutableArray<NSString*>* _Nonnull)numberMatchArray;

/*
 获取姓名匹配的人的拼音，及匹配位置
 localID:姓名匹配的联系人ID
 pinYin:返回值-拼音串
 matchPos:拼音的匹配位置
 */
#pragma mark - 结果匹配
///@brief 获取姓名匹配的人的拼音，及匹配位置
///@param localID 姓名匹配的联系人ID
///@param oStr 原字符串
///@param matchPosInHZ 汉字的匹配位置
- (BOOL)getPinYin:(NSInteger)localID orginStr:(NSString* _Nonnull)oStr matchPosHZ:(NSMutableArray<NSNumber*>* _Nonnull)matchPosInHZ;

/*
 获取号码匹配的人的所有匹配号码，及匹配位置
 localID:号码匹配的联系人ID
 Number:返回值-所有匹配的号码
 matchPos:号码对应的匹配位置
 */
///@brief 获取号码匹配的人的所有匹配号码，及匹配位置
///@param localID 号码匹配的联系人ID
///@param oStr 原字符串
///@param matchPosArray 号码对应的匹配位置
- (BOOL)getNumber:(NSInteger)localID orginStr:(NSString* _Nonnull)oStr matchPos:(NSMutableArray<NSArray<NSNumber*>*>* _Nonnull)matchPosArray;

#pragma mark - 其他
///@brief 重置搜索——清空搜索缓存
- (void)reset;

///@brief 26字母对应的数字,也就是T9规则,例如常规T9就是@"22233344455566677778889999"
- (void)setMatchFunction:(NSString* _Nonnull)matchFunc;

///@brief 其他字母对应的数字,例如俄语T9就是@"222233334444555566667777788889999"
- (void)setMatchOtherFunction:(NSString* _Nonnull)matchFunc;

///@brief 额外支持的检索语言,0为无其他支持语言,1为额外支持俄语
- (void)setSupportedLanguage:(int)sl;

@end

NS_ASSUME_NONNULL_END
