#include "main.h"

int autonSelection = TEST; // specifies the default auton selected

/* Set up button map for solo and duo autonomouses */
static const char *soloBtnmMap[] = {"Auton 1", "Auton 2", "Auton 3", "\n", "Auton 4", "Auton 5", "\n", "Do Nothing", ""};
static const char *duoBtnmMap[] = {"Auton 1", "Auton 2", "Auton 3", "\n", "Auton 4", "Auton 5", "\n", "Do Nothing", ""};

/* Selector code when solo tab is pressed */
lv_res_t soloBtnmAction(lv_obj_t *btnm, const char *txt){
	printf("solo button: %s released\n", txt);
	lv_theme_t *th = lv_theme_nemo_init(0, NULL);
	lv_theme_set_current(th);
	if (strcmp(txt, "Auton 1") == 0)
	{
		autonSelection = RED_1;
	}
	if (strcmp(txt, "Auton 2") == 0)
	{
		autonSelection = RED_2;
	}
	if (strcmp(txt, "Auton 3") == 0)
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

	return LV_RES_OK; // return OK because the button matrix is not deleted
}


/* Selector code when duo tab is pressed */
lv_res_t duoBtnmAction(lv_obj_t *btnm, const char *txt)
{
	printf("duo button: %s released\n", txt);

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
	
	printf("skills pressed");
	autonSelection = SKILLS;
	return LV_RES_OK;
}

/* Selector code for when Test tab is pressed */
lv_res_t testBtnAction(lv_obj_t *btn)
{
	// lvgl theme
	lv_theme_t *th = lv_theme_nemo_init(286, NULL);
	lv_theme_set_current(th);
	
	lv_style_scr.body.main_color = LV_COLOR_BLACK; 
	
	autonSelection = TEST;
	return LV_RES_OK;
}

/* INITIALIZE SELECTOR */
void selectorInit(){
	// lvgl theme
	lv_theme_t *th = lv_theme_nemo_init(286, NULL);
	lv_theme_set_current(th);

	// create a tab view object
	lv_obj_t *tabview;
	tabview = lv_tabview_create(lv_scr_act(), NULL);

	// add 4 tabs (the tabs are page (lv_page) and can be scrolled
	lv_obj_t *soloTab = lv_tabview_add_tab(tabview, "Solo");
	lv_obj_t *duoTab = lv_tabview_add_tab(tabview, "Duo");
	lv_obj_t *skillsTab = lv_tabview_add_tab(tabview, "Skills");
	lv_obj_t *testTab = lv_tabview_add_tab(tabview, "Testing");

	// add content to the tabs
	// button matrix
	lv_obj_t *soloBtnm = lv_btnm_create(soloTab, NULL);
	lv_btnm_set_map(soloBtnm, soloBtnmMap);
	lv_btnm_set_action(soloBtnm, soloBtnmAction);
	lv_btnm_set_toggle(soloBtnm, true, 3);//3
	lv_obj_set_size(soloBtnm, 450, 130);
	lv_obj_set_pos(soloBtnm, 0, 100);
	lv_obj_align(soloBtnm, NULL, LV_ALIGN_CENTER, 0, 0);

	// duo tab
	lv_obj_t *duoBtnm = lv_btnm_create(duoTab, NULL);
	lv_btnm_set_map(duoBtnm, duoBtnmMap);
	lv_btnm_set_action(duoBtnm, duoBtnmAction);
	lv_btnm_set_toggle(duoBtnm, true, 3);
	lv_obj_set_size(duoBtnm, 450, 130);
	lv_obj_set_pos(duoBtnm, 0, 100);
	lv_obj_align(duoBtnm, NULL, LV_ALIGN_CENTER, 0, 0);

	// skills tab
	lv_obj_t *skillsBtn = lv_btn_create(skillsTab, NULL);
	lv_obj_t *label = lv_label_create(skillsBtn, NULL);
	lv_label_set_text(label, "Skills");
	lv_btn_set_action(skillsBtn, LV_BTN_ACTION_CLICK, skillsBtnAction);
	// lv_btn_set_state(skillsBtn, LV_BTN_STATE_TGL_REL);
	lv_obj_set_size(skillsBtn, 450, 50);
	lv_obj_set_pos(skillsBtn, 0, 100);
	lv_obj_align(skillsBtn, NULL, LV_ALIGN_CENTER, 0, 0);

	// test tab
	lv_obj_t *testBtn = lv_btn_create(testTab, NULL);
	lv_obj_t *label2 = lv_label_create(testBtn, NULL);
	lv_label_set_text(label2, "Testing Script");
	lv_btn_set_action(testBtn, LV_BTN_ACTION_CLICK, testBtnAction);
	// lv_btn_set_state(testBtn, LV_BTN_STATE_TGL_REL);
	lv_obj_set_size(testBtn, 450, 50);
	lv_obj_set_pos(testBtn, 0, 100);
	lv_obj_align(testBtn, NULL, LV_ALIGN_CENTER, 0, 0);
}