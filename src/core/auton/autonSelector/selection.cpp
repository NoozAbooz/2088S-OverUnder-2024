/**
 * @file main.cpp
 * @author Michael Zheng
 * @brief Main auton select on the brain, built using LVGL
 * @date 2023-03-10
 */

#include "main.h"

int autonSelection = RED_5; // specifies the default auton selected

/* Set up button map for autonomous */
static const char *btnmMap[] = {"Rollers + 3 Disc", "Rollers + 3 Disc", "Rollers + Low Goal", "\n", "Auton 4", "Auton 5", "\n", "Do Nothing"};

/* Selector code when Red tab is pressed */
lv_res_t redBtnmAction(lv_obj_t *btnm, const char *txt){
	lv_theme_t *th = lv_theme_nemo_init(0, NULL);
	lv_theme_set_current(th);
	if (strcmp(txt, "Roller + 6") == 0) 
	{
		autonSelection = RED_1;
	}
	if (strcmp(txt, "Rollers + 3 Disc") == 0)
	{
		autonSelection = RED_2;
	}
	if (strcmp(txt, "Rollers + Low Goal") == 0)
	{
		autonSelection = RED_3;
	}
	if (strcmp(txt, "Auton 4") == 0)
	{
		autonSelection = RED_4;
	}
	if (strcmp(txt, "Auton 5") == 0)
	{
		autonSelection = RED_5;
	}
	if (strcmp(txt, "Do Nothing") == 0)
	{
		autonSelection = NOTHING;
	}

	return LV_RES_OK;
}

/* Selector code when Blue tab is pressed */
lv_res_t blueBtnmAction(lv_obj_t *btnm, const char *txt)
{
	printf("blue button: %s released\n", txt);

	lv_theme_t *th = lv_theme_nemo_init(230, NULL);
	lv_theme_set_current(th);

	if (strcmp(txt, "Auton 1") == 0)
	{
		autonSelection = BLUE_1;
	}
	if (strcmp(txt, "Auton 2") == 0)
	{
		autonSelection = BLUE_2;
	}
	if (strcmp(txt, "Auton 3") == 0)
	{
		autonSelection = BLUE_3;
	}
	if (strcmp(txt, "Auton 4") == 0)
	{
		autonSelection = BLUE_4;
	}
	if (strcmp(txt, "Auton 5") == 0)
	{
		autonSelection = BLUE_5;
	}
	if (strcmp(txt, "Do Nothing") == 0)
	{
		autonSelection = NOTHING;
	}

	return LV_RES_OK;
}

/* Selector code for when Skills tab is pressed */
lv_res_t skillsBtnAction(lv_obj_t *btn)
{
	// lvgl theme
	lv_theme_t *th = lv_theme_nemo_init(286, NULL);
	lv_theme_set_current(th);
	
	lv_style_scr.body.main_color = LV_COLOR_BLACK; 

	autonSelection = SKILLS;
	return LV_RES_OK;
}


/* Init selector */
void selectorInit(){
	// lvgl theme
	lv_theme_t *th = lv_theme_nemo_init(286, NULL);
	lv_theme_set_current(th);
	lv_obj_t *tabview;
	tabview = lv_tabview_create(lv_scr_act(), NULL);

	// Add 3 tabs
	lv_obj_t *redTab = lv_tabview_add_tab(tabview, "Solo");
	lv_obj_t *blueTab = lv_tabview_add_tab(tabview, "Duo");
	lv_obj_t *skillsTab = lv_tabview_add_tab(tabview, "Skills");
	lv_obj_t *testTab = lv_tabview_add_tab(tabview, "Test");

	// Red tab
	lv_obj_t *redBtnm = lv_btnm_create(redTab, NULL);
	lv_btnm_set_map(redBtnm, btnmMap);
	lv_btnm_set_action(redBtnm, redBtnmAction);
	lv_btnm_set_toggle(redBtnm, true, 3);//3
	lv_obj_set_size(redBtnm, 450, 130);
	lv_obj_set_pos(redBtnm, 0, 100);
	lv_obj_align(redBtnm, NULL, LV_ALIGN_CENTER, 0, 0);

	// Blue tab
	lv_obj_t *blueBtnm = lv_btnm_create(blueTab, NULL);
	lv_btnm_set_map(blueBtnm, btnmMap);
	lv_btnm_set_action(blueBtnm, blueBtnmAction);
	lv_btnm_set_toggle(blueBtnm, true, 3);
	lv_obj_set_size(blueBtnm, 450, 130);
	lv_obj_set_pos(blueBtnm, 0, 100);
	lv_obj_align(blueBtnm, NULL, LV_ALIGN_CENTER, 0, 0);

	// Skills tab
	lv_obj_t *skillsBtn = lv_btn_create(skillsTab, NULL);
	lv_obj_t *label = lv_label_create(skillsBtn, NULL);
	lv_label_set_text(label, "Skills");
	lv_btn_set_action(skillsBtn, LV_BTN_ACTION_CLICK, skillsBtnAction);
	// lv_btn_set_state(skillsBtn, LV_BTN_STATE_TGL_REL);
	lv_obj_set_size(skillsBtn, 450, 50);
	lv_obj_set_pos(skillsBtn, 0, 100);
	lv_obj_align(skillsBtn, NULL, LV_ALIGN_CENTER, 0, 0);

	// Testing tab
	lv_obj_t *testBtn = lv_btn_create(testTab, NULL);
	lv_obj_t *label = lv_label_create(testBtn, NULL);

	lv_obj_t *testBtnm = lv_btnm_create(testTab, NULL);
	lv_btnm_set_map(redBtnm, btnmMap);
	lv_btnm_set_action(redBtnm, redBtnmAction);
	lv_btnm_set_toggle(redBtnm, true, 3);//3
	lv_obj_set_size(redBtnm, 450, 130);
	lv_obj_set_pos(redBtnm, 0, 100);
	lv_obj_align(redBtnm, NULL, LV_ALIGN_CENTER, 0, 0);
}