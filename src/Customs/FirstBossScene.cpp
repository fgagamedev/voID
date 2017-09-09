#include "Customs/FirstBossScene.hpp"

FirstBossScene::FirstBossScene() {}

/**
    @brief that function is for when tha state is activated. Then is created the
    map, player, boss, light, rain, show, thunder, player attack and hit.
*/
void FirstBossScene::OnActivation() {
    CreateMap();//This must be the first function to be called
    CreatePlayer();
    CreateBoss();

    //CreateFirstBossAttack();
    CreateLight();
    CreateRain();
    CreateSnow();
    CreateThunder();
    CreatePlayerAttack();
    CreatePlayerHit();
    //FirstBossController::GetInstance()->StartBossFight();

  /*
  CameraSystem::GetInstance()->ZoomOut( 100,
                                        SceneManager::GetInstance()->GetCurrentScene()->GetGameObject("NakedMan"),
                                        SceneManager::GetInstance()->GetCurrentScene());
  CameraSystem::GetInstance()->ZoomIn(  1,
                                      SceneManager::GetInstance()->GetCurrentScene()->GetGameObject("NakedMan"),
                                      SceneManager::GetInstance()->GetCurrentScene());
  CameraSystem::GetInstance()->currentZoom -=25;
  */
}

/**
    @brief that function is for when the state is deactivated, so nothing are
    created.
*/
void FirstBossScene::OnDeactivation() {}

/**
    @brief that function is for when the state is shown. Nothing are create here.
*/
void FirstBossScene::OnShown() {
  //CameraSystem::GetInstance()->MoveUp(2,SceneManager::GetInstance()->GetCurrentScene());
  //CameraSystem::GetInstance()->MoveUp(2,SceneManager::GetInstance()->GetCurrentScene());
}

/**
    @brief that function is for the state is hidden.
*/
void FirstBossScene::OnHidden() {}


/**
    @brief that function is for to create the map of the game.
*/
void FirstBossScene::CreateMap() {
  //Original resolution is 2048/2048
  //6144,6144 = 3x
  /*auto map = new GameObject("Map", new Vector(-5250 ,-5000),10500,10500);
  // Renderer
  auto mapImage = new Image("assets/world.png", 0, 0, 3500, 3500);
  auto mapRenderer = new Renderer(map, mapImage);
  */
  //auto map =  SceneManager::GetInstance()->GetScene("Gameplay")->GetGameObject("Map");
  // Script
  //auto mapScript = new MapScript(map);
  //AddGameObject(map);

}

/**
    @brief that function create the player when the state are active. After create,
    they add the "nakedMan" (player) as a game object and add the player to the game.
*/
void FirstBossScene::CreatePlayer() {
    int xPos = 0, yPos = 0;
    xPos = EngineGlobals::screen_width / 2 - 96 / 2;
    yPos = EngineGlobals::screen_height / 2 - 96 / 2;
    auto nakedMan = new GameObject("NakedMan", new Vector(xPos,yPos),96 ,
                                                                     96, 1);
    // Script
    auto nakedManScript = new NakedManScript(nakedMan);
    AddGameObject(nakedMan);
    FirstBossController::GetInstance()->AddPlayer(nakedMan);
}

/**
    @brief that function create the boss when the state are active. After create,
    they add the "firstBoss" (boss) as a game object and add the boss to the game.
*/
void FirstBossScene::CreateBoss() {

    auto FirstBossCentralEffect = new GameObject("FirstBossCentralEffect",
                                            new Vector(0,0),211.86,211.86, 1);
    auto firstBossCentralEffectScript = new  FirstBossCentralEffectScript
                                                    (FirstBossCentralEffect);
    AddGameObject(FirstBossCentralEffect);

    auto firstBoss = new GameObject("FirstBoss", new Vector(0,0),690,930, 2);

    //Tag
    firstBoss->SetTag("FirstBoss");

    // Script
    auto firstBossScript = new  FirstBossScript(firstBoss);
    AddGameObject(firstBoss);
    FirstBossController::GetInstance()->AddBoss(firstBoss);
}


/**
    @brief that function create the first boss attack when the state are active. After create,
    they add the "firstBossAttack" as a game object and add the boss attack.
*/
void FirstBossScene::CreateFirstBossAttack() {

    auto firstBossAttack = new GameObject("FirstBossAttack", new Vector(-4750,
                                                            -1700),39,147, 1);

    //Tag
    firstBossAttack->SetTag("FirstBossAtack");

    // Script
    auto firstBossAttackScript = new  FirstBossAttackScript(firstBossAttack);
    AddGameObject(firstBossAttack);
    FirstBossController::GetInstance()->AddTentacle(firstBossAttack);
}

/**
    @brief that function create the player attack when the state are active. After create,
    they add the "PlayerAttack" as a game object and add the player attack.
*/
void FirstBossScene::CreatePlayerAttack() {

    //Creating Bullets
    for (int counter = 1; counter < 10; counter++) {
        std::string bulletName = "Bullet" + std::to_string(counter);
        auto bullet = new GameObject(bulletName, new Vector(100 * counter, 0),
                                                                   15, 15, 2);
        bullet->SetTag("Bullet");

        auto bulletScript = new  PlayerAttackScript(bullet);
        //MissileController::GetInstance()->AddPlayer(bullet);
        AddGameObject(bullet);
    //bullet->active = false;
  }
}

/**
    @brief that function create the rain when the state are active. After create,
    they add the "Rain" as a game object and add the rain to the game.
*/
void FirstBossScene::CreateRain() {

    auto rain = new GameObject("Rain", new Vector(0,0),1024,800,1);
    auto rainScript = new RainScript(rain);
    AddGameObject(rain);
}

/**
    @brief that function create the player hit when the state are active. After create,
    they add the "Hit" as a game object and add the player attack.
*/
void FirstBossScene::CreatePlayerHit() {

    auto hit = new GameObject("Hit", new Vector(0,0),1024,800,1);

    auto hitScript = new HitScript(hit);
    AddGameObject(hit);
}


/**
    @brief that function create the thunder when the state are active. After create,
    they add the "Rain" as a game object and add the thunder to the game.
*/
void FirstBossScene::CreateThunder() {

    auto thunder = new GameObject("Rain", new Vector(200,0),113,267,1);
    auto thunderScript = new ThunderScript(thunder);
    AddGameObject(thunder);
}


/**
    @brief that function create the snow when the state are active. After create,
    they add the "Snow" as a game object and add the snow to the game.
*/
void FirstBossScene::CreateSnow(){

    auto snow = new GameObject("Snow", new Vector(0,0),1024,800,1);
    auto snowScript = new SnowScript(snow);
    AddGameObject(snow);
}

/**
    @brief that function create the light when the state are active. After create,
    they add the "Light" as a game object and add the light to the game.
*/
void FirstBossScene::CreateLight() {

  auto light = new GameObject("Light", new Vector(0,0),2*1024,2*800,1);
 //auto lightImage = new Image("assets/luz.png",0,0,682, 512);
 //auto mapRenderer = new Renderer(light, lightImage);
  auto lightScript = new LightScript(light);
  AddGameObject(light);
}
/*
void GamePlayScene::CreateAmmoCounter() {

  auto ammo = new GameObject("Ammo", new Vector(2,2),200,200,3);
  auto messengerText = new UIText(ammo, "15", "assets/UIpack/Font/kenvector_future_thin.ttf",
                 100, 255, 255, 255, 255, 1);
  //auto lightScript = new LightScript(light);
  AddGameObject(ammo);

}
*/
