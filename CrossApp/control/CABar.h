//
//  CABar.h
//  CrossApp
//
//  Created by Li Yuanfeng on 14-4-14.
//  Copyright (c) 2014 http://9miao.com All rights reserved.
//

#ifndef __CrossAppx__CABar__
#define __CrossAppx__CABar__

#include <iostream>
#include "view/CAView.h"
#include "CAButton.h"
#include "CASegmentedControl.h"
#include "controller/CABarItem.h"
#include "basics/CASTLContainer.h"

NS_CC_BEGIN

class CANavigationBar;
class CC_DLL CANavigationBarDelegate
{
public:
    
    virtual void navigationPopViewController(CANavigationBar* navigationBar, bool animated) = 0;
    
};

class CC_DLL CANavigationBar
: public CAView
{
    
public:
    
    CREATE_FUNC(CANavigationBar);

public:
    
    CANavigationBar();
    
    virtual ~CANavigationBar();
    
    virtual bool init();
    
    virtual void onEnterTransitionDidFinish();
    
    virtual void onExitTransitionDidStart();
    
    virtual void setBackGroundView(CAView* var);
    
    CC_SYNTHESIZE_READONLY(CAView*, m_pBackGroundView, BackGroundView);

    virtual void setTitleColor(const CAColor4B& color);
    
    CC_SYNTHESIZE_READONLY_PASS_BY_REF(CAColor4B, m_cTitleColor, TitleColor);
    
    virtual void setButtonColor(const CAColor4B& color);
    
    CC_SYNTHESIZE_READONLY_PASS_BY_REF(CAColor4B, m_cButtonColor, ButtonColor);
    
    CC_SYNTHESIZE(CANavigationBarDelegate* , m_pDelegate, Delegate);
    
    virtual void setItem(CANavigationBarItem* item);
    
    CC_SYNTHESIZE_READONLY(CANavigationBarItem*, m_pItem, Item);

protected:
    
    void showBackGround();
    
    void showTitle();
    
    void showLeftButton();
    
    void showRightButton();
    
    void goBack(CAControl* btn, CCPoint point);
    
    void updateNavigationBar();
    
protected:
    
    CAView* m_pTitle;
    
    std::vector<CAButton*> m_pLeftButtons;
    
    std::vector<CAButton*> m_pRightButtons;
};

class CATabBar;
class CC_DLL CATabBarDelegate
{
public:
    
    virtual void tabBarSelectedItem(CATabBar* tabBar, CATabBarItem* item, unsigned int index) = 0;
    
    virtual void tabBarClickToForbidSelectedItem(CATabBar* tabBar, CATabBarItem* item, unsigned int index){};
    
};

class CC_DLL CATabBar
:public CAView
{
    
public:
    
    static CATabBar* create(const std::vector<CATabBarItem*>& items, const CCSize& size = CCSizeZero);
    
    void setItems(const std::vector<CATabBarItem*>& items);

	void setItems(const CAVector<CATabBarItem*>& items);
    
public:

    CATabBar();
    
    virtual ~CATabBar();
    
    virtual bool init(const std::vector<CATabBarItem*>& items, const CCSize& size = CCSizeZero);
    
    CC_PROPERTY(CAView*, m_pBackGroundView, BackGroundView);
    
    CC_PROPERTY(CAView*, m_pSelectedBackGroundView, SelectedBackGroundView);
    
    CC_PROPERTY(CAImage*, m_pSelectedBackGroundImage, SelectedBackGroundImage);
    
    CC_PROPERTY(CAView*, m_pSelectedIndicatorView, SelectedIndicatorView);
    
    CC_PROPERTY(CAImage*, m_pSelectedIndicatorImage, SelectedIndicatorImage);
    
    CC_PROPERTY_PASS_BY_REF(CAColor4B, m_sTitleColor, TitleColorForNormal);
    
    CC_PROPERTY_PASS_BY_REF(CAColor4B, m_sSelectedTitleColor, TitleColorForSelected);
    
    CC_SYNTHESIZE(unsigned int, m_nMaxShowCount, MaxShowCount)
    
    CC_SYNTHESIZE(CATabBarDelegate* , m_pDelegate, Delegate);
    
    CC_SYNTHESIZE_READONLY_PASS_BY_REF(CAVector<CATabBarItem*>, m_pItems, Items);
    
    CC_SYNTHESIZE_READONLY(int, m_nSelectedIndex, SelectedIndex);
    
    void setSelectedAtIndex(int index);
    
    void setForbidSelectedAtIndex(int index);
    
    void showSelectedIndicator();
    
    void replaceItemAtIndex(size_t index, CATabBarItem* item);
    
    const CCRect& getSegmentedControlFrame();
    
protected:
    
    void showBackGround();
    
    void showItems();
    
    void setTouchSelected(CAControl* control, CCPoint point);
    
    void setTouchUpInSide(CAControl* control, CCPoint point);
    
protected:
    
    CATabBarItem* m_pSelectedItem;
    
    CCSize m_cItemSize;

    CASegmentedControl* m_pSegmentedControl;
};


NS_CC_END

#endif /* defined(__CrossAppx__CABar__) */
