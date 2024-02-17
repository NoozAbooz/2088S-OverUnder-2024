#include "main.h"

using namespace pros;
// Modified... original credit: https://github.com/kunwarsahni01/Vex-Autonomous-Selector
namespace selector
{
	int auton = 9;
	void tabWatcher() {
		while (1) {
			if(button.get_new_press()) {
				auton =+ 1;

				if(auton > 9) {
					auton = 0;
				}
			}

			pros::delay(20);
		}
	}

	void init() {
		// start tab watcher
		pros::Task tabWatcher_task(tabWatcher);
	}

	// lv_res_t switchhandle1(lv_obj_t *s);
	// 		lv_res_t switchhandle2(lv_obj_t *s);
	// 				lv_res_t switchhandle3(lv_obj_t *s);
	// int auton;
	// int autonCount;
	// const char *btnmMap[] = {"", "", "", "", "", "", "", "", "", "", ""}; // up to 10 autons
	// const char *b[] = {AUTONS, ""};
	// lv_obj_t *tabview;
	// lv_obj_t *redBtnm;
	// lv_obj_t *blueBtnm;
	// lv_obj_t *l;
	// lv_res_t redBtnmAction(lv_obj_t *btnm, const char *txt)
	// {
	// 	// printf("red button: %s released\n", txt);

	// 	for (int i = 0; i < autonCount; i++)
	// 	{
	// 		if (strcmp(txt, btnmMap[i]) == 0)
	// 		{
	// 			auton = i + 1;
	// 		}
	// 	}

	// 	return LV_RES_OK; // return OK because the button matrix is not deleted
	// }

	// lv_res_t blueBtnmAction(lv_obj_t *btnm, const char *txt)
	// {
	// 	// printf("blue button: %s released\n", txt);

	// 	for (int i = 0; i < autonCount; i++)
	// 	{
	// 		if (strcmp(txt, btnmMap[i]) == 0)
	// 		{
	// 			auton = -(i + 1);
	// 		}
	// 	}

	// 	return LV_RES_OK; // return OK because the button matrix is not deleted
	// }

	// lv_res_t skillsBtnAction(lv_obj_t *btn)
	// {
	// 	// printf("skills pressed");
	// 	auton = 0;
	// 	return LV_RES_OK;
	// }

	// int tabWatcher()
	// {
	// 	int activeTab = lv_tabview_get_tab_act(tabview);
	// 	while (1)
	// 	{
	// 		int currentTab = lv_tabview_get_tab_act(tabview);

	// 		if (currentTab != activeTab)
	// 		{
	// 			activeTab = currentTab;
	// 			if (activeTab == 0)
	// 			{
	// 				if (auton == 0)
	// 					auton = 1;
	// 				auton = abs(auton);
	// 				lv_btnm_set_toggle(redBtnm, true, abs(auton) - 1);
	// 			}
	// 			else if (activeTab == 1)
	// 			{
	// 				if (auton == 0)
	// 					auton = -1;
	// 				auton = -abs(auton);
	// 				lv_btnm_set_toggle(blueBtnm, true, abs(auton) - 1);
	// 			}
	// 			else
	// 			{
	// 				auton = 0;
	// 			}
	// 		}

	// 		pros::delay(20);
	// 	}
	// }

	// void init(int hue, int default_auton, const char **autons)
	// {

	// 	int i = 0;
	// 	do
	// 	{
	// 		memcpy(&btnmMap[i], &autons[i], sizeof(&autons));
	// 		i++;
	// 	} while (strcmp(autons[i], "") != 0);

	// 	autonCount = i;
	// 	auton = default_auton;

	// 	// lvgl theme
	// 	lv_theme_t *th = lv_theme_alien_init(hue, NULL); // Set a HUE value and keep font default RED
	// 	lv_theme_set_current(th);

	// 	// create a tab view object
	// 	tabview = lv_tabview_create(lv_scr_act(), NULL);
	// 	lv_tabview_set_anim_time(tabview, 500);

	// 	// add 3 tabs (the tabs are page (lv_page) and can be scrolled
	// 	lv_obj_t *redTab = lv_tabview_add_tab(tabview, "Red");
	// 	lv_obj_t *blueTab = lv_tabview_add_tab(tabview, "Blue");
	// 	lv_obj_t *skillsTab = lv_tabview_add_tab(tabview, "Skills");
		
	// 	lv_obj_t *pneumatics = lv_tabview_add_tab(tabview, "Pneumatics");
	// 	// set default tab
	// 	if (auton < 0)
	// 	{
	// 		lv_tabview_set_tab_act(tabview, 1, LV_ANIM_NONE);
	// 	}
	// 	else if (auton == 0)
	// 	{
	// 		lv_tabview_set_tab_act(tabview, 2, LV_ANIM_NONE);
	// 	}
	// 	// add content to the tabs
	// 	// button matrix
	// 	redBtnm = lv_btnm_create(redTab, NULL);
	// 	lv_btnm_set_map(redBtnm, btnmMap);
	// 	lv_btnm_set_action(redBtnm, redBtnmAction);
	// 	lv_btnm_set_toggle(redBtnm, true, abs(auton) - 1); // 3
	// 	lv_obj_set_size(redBtnm, 450, 50);
	// 	lv_obj_set_pos(redBtnm, 0, 100);
		
	// 	lv_obj_align(redBtnm, NULL, LV_ALIGN_CENTER, 0, 0);

	// 	// blue tab
	// 	blueBtnm = lv_btnm_create(blueTab, NULL);
		
	// 	lv_btnm_set_map(blueBtnm, btnmMap);
	// 	lv_btnm_set_action(blueBtnm, *blueBtnmAction);
	// 	lv_btnm_set_toggle(blueBtnm, true, abs(auton) - 1);
	// 	lv_obj_set_size(blueBtnm, 450, 50);
	// 	lv_obj_set_pos(blueBtnm, 0, 100);
	// 	lv_obj_align(blueBtnm, NULL, LV_ALIGN_CENTER, 0, 0);

	// 	// skills tab
	// 	lv_obj_t *skillsBtn = lv_btn_create(skillsTab, NULL);
	// 	lv_obj_t *label = lv_label_create(skillsBtn, NULL);
	// 	lv_label_set_text(label, "Skills");
	// 	lv_btn_set_action(skillsBtn, LV_BTN_ACTION_CLICK, *skillsBtnAction);
	// 	// lv_btn_set_state(skillsBtn, LV_BTN_STATE_TGL_REL);
	// 	lv_obj_set_size(skillsBtn, 450, 50);
	// 	lv_obj_set_pos(skillsBtn, 0, 100);
		
	// 	lv_obj_t *cylinder1 = lv_sw_create(pneumatics, NULL);
	// 	lv_sw_set_action(cylinder1, switchhandle1);
	// 	lv_obj_align(cylinder1, pneumatics, LV_ALIGN_IN_TOP_MID, 0, 10);

	// 	lv_obj_t *cylinder2 = lv_sw_create(pneumatics, NULL);
	// 	lv_sw_set_action(cylinder2, switchhandle2);
	// 	lv_obj_align(cylinder2, pneumatics, LV_ALIGN_CENTER, 0,20);

	// 	lv_obj_t *cylinder3 = lv_sw_create(pneumatics, NULL);
	// 	lv_sw_set_action(cylinder3, switchhandle3);
	// 	lv_obj_align(cylinder3, pneumatics, LV_ALIGN_IN_BOTTOM_MID, 0, 10);

	// 	// start tab watcher
	// 	pros::Task tabWatcher_task(tabWatcher);
	// }
	// lv_res_t switchhandle1(lv_obj_t *s){
	// 	ADIDigitalOut p ('F');
	// 	p.set_value(lv_sw_get_state(s));
	// 	return LV_RES_OK;
	// }
	// 	lv_res_t switchhandle2(lv_obj_t *s){
	// 	ADIDigitalOut p ('G');
	// 	p.set_value(lv_sw_get_state(s));
	// 	return LV_RES_OK;
	// }
	// 	lv_res_t switchhandle3(lv_obj_t *s){
	// 	ADIDigitalOut p ('H');
	// 	p.set_value(lv_sw_get_state(s));
	// 	return LV_RES_OK;
	// }
} // namespace selector