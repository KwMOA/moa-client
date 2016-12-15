LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos/audio/include)

LOCAL_MODULE := MyGame_shared

LOCAL_MODULE_FILENAME := libMyGame

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/Act.cpp \
                   ../../Classes/ActAttack.cpp \
                   ../../Classes/ActRun.cpp \
                   ../../Classes/AiPlayer.cpp \
                   ../../Classes/AttackInfluence.cpp \
                   ../../Classes/AutoTaskQueue.cpp \
                   ../../Classes/BaseLayer.cpp \
                   ../../Classes/BaseObject.cpp \
                   ../../Classes/Building_1.cpp \
                   ../../Classes/Building_2.cpp \
                   ../../Classes/Building_3.cpp \
                   ../../Classes/Building_4.cpp \
                   ../../Classes/Building_5.cpp \
                   ../../Classes/Building_6.cpp \
                   ../../Classes/Building_7.cpp \
                   ../../Classes/Building_8.cpp \
                   ../../Classes/Building_9.cpp \
                   ../../Classes/Building_10.cpp \
                   ../../Classes/Building_11.cpp \
                   ../../Classes/Building_12.cpp \
                   ../../Classes/Building.cpp \
                   ../../Classes/TechChecker.cpp \
                   ../../Classes/ControlLayer.cpp \
                   ../../Classes/CreateAccountLayer.cpp \
                   ../../Classes/CustomButton.cpp \
                   ../../Classes/CustomPopUp.cpp \
                   ../../Classes/GameClient.cpp \
                   ../../Classes/GameManager.cpp \
                   ../../Classes/GamePlayer.cpp \
                   ../../Classes/GameScene.cpp \
                   ../../Classes/GameWorld.cpp \
                   ../../Classes/HelloWorldScene.cpp \
                   ../../Classes/Influence.cpp \
                   ../../Classes/JsonReader.cpp \
                   ../../Classes/LinkedList.cpp \
                   ../../Classes/LobbyAIGameLayer.cpp \
                   ../../Classes/LobbyBoardLayer.cpp \
                   ../../Classes/LobbyChannelLayer.cpp \
                   ../../Classes/LobbyClanLayer.cpp \
                   ../../Classes/LobbyFriendLayer.cpp \
                   ../../Classes/LobbyGameLayer.cpp \
                   ../../Classes/LobbyMainLayer.cpp \
                   ../../Classes/LobbyRankGameLayer.cpp \
                   ../../Classes/LobbyRankingLayer.cpp \
                   ../../Classes/LobbyScene.cpp \
                   ../../Classes/LoginLayer.cpp \
                   ../../Classes/LoginScene.cpp \
                   ../../Classes/LogManager.cpp \
                   ../../Classes/MenuButtonLayer.cpp \
                   ../../Classes/MiniMapLayer.cpp \
                   ../../Classes/MyInfoLayer.cpp \
                   ../../Classes/Network.cpp \
                   ../../Classes/NetworkManager.cpp \
                   ../../Classes/ObjectInfos.cpp \
                   ../../Classes/ResultScene.cpp \
                   ../../Classes/StaticObject.cpp \
                   ../../Classes/TaskManager.cpp \
                   ../../Classes/TopLayer.cpp \
                   ../../Classes/Unit_1.cpp \
                   ../../Classes/Unit_2.cpp \
                   ../../Classes/Unit_3.cpp \
                   ../../Classes/Unit_4.cpp \
                   ../../Classes/Unit_5.cpp \
                   ../../Classes/Unit_6.cpp \
                   ../../Classes/Unit_7.cpp \
                   ../../Classes/Unit_8.cpp \
                   ../../Classes/Unit_9.cpp \
                   ../../Classes/Unit.cpp \
                   ../../Classes/Upgrade_1.cpp \
                   ../../Classes/Upgrade_2.cpp \
                   ../../Classes/Upgrade_3.cpp \
                   ../../Classes/Upgrade_4.cpp \
                   ../../Classes/Upgrade_5.cpp \
                   ../../Classes/Upgrade_6.cpp \
                   ../../Classes/Upgrade_7.cpp \
                   ../../Classes/Upgrade_8.cpp \
                   ../../Classes/Upgrade_9.cpp \
                   ../../Classes/Upgrade_10.cpp \
                   ../../Classes/Upgrade_11.cpp \
                   ../../Classes/Upgrade_12.cpp \
                   ../../Classes/Upgrade_13.cpp \
                   ../../Classes/Upgrade_14.cpp \
                   ../../Classes/Upgrade_15.cpp \
                   ../../Classes/Upgrade_16.cpp \
                   ../../Classes/Upgrade_17.cpp \
                   ../../Classes/Upgrade_18.cpp \
                   ../../Classes/Upgrade_19.cpp \
                   ../../Classes/Upgrade_20.cpp \
                   ../../Classes/Upgrade_21.cpp \
                   ../../Classes/Upgrade_22.cpp \
                   ../../Classes/Upgrade_23.cpp \
                   ../../Classes/Upgrade_24.cpp \
                   ../../Classes/Upgrade.cpp \
                   ../../Classes/UserInfoLayer.cpp \
                   ../../Classes/UserListLayer.cpp \
                   ../../Classes/ResultLayer.cpp \
                   ../../Classes/InfoLayer.cpp \



LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
