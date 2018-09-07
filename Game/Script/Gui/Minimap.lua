Minimap = class(Gui)

function Minimap:Init()
    -- Hero
    Events:RegisterListener("hero.create", self.OnHeroCreate)
    Events:RegisterListener("hero.destroy", self.OnHeroDestroy)
    -- Boss
    Events:RegisterListener("boss.create", self.OnBossCreate)
    Events:RegisterListener("boss.destroy", self.OnBossDestroy)

    -- Store reference to minimap panel
    self.minimap_panel = Gui.GetElementById("minimap")
    -- Make sure there are limits (this is shorter way than if conditions)
    self.minimap_panel["min_x"] = self.minimap_panel["min_x"] or 0
    self.minimap_panel["min_y"] = self.minimap_panel["min_y"] or 0
    self.minimap_panel["max_x"] = self.minimap_panel["max_x"] or 0
    self.minimap_panel["max_y"] = self.minimap_panel["max_y"] or 0

    -- Position update Timer
    Timers.CreateTimer(0.25, function()
        local min_x = self.minimap_panel.min_x
        local min_y = self.minimap_panel.min_y
        local max_x = self.minimap_panel.max_x
        local max_y = self.minimap_panel.max_y
        local size_x = max_x - min_x
        local size_y = max_y - min_y

        -- Update position of heroes on minimap
        for unitId, heroIcon in pairs(heroIcons) do
            local unit = Map.Current.FindUnitById(unitId)
            if unit then
                local position = unit:GetPosition()
                if position and
                    position.x >= min_x and position.x <= max_x and
                    position.y >= min_y and position.y <= max_y then
                    heroIcon["visible"] = true
                    heroIcon["position_x"] = (position.x - min_x) / size_x
                    heroIcon["position_y"] = (position.y - min_y) / size_y
                else -- not position
                    heroIcon["visible"] = false
                    heroIcon["position_x"] = 0
                    heroIcon["position_y"] = 0
                end
            else -- not unit
                heroIcon["visible"] = false
                heroIcon["position_x"] = 0
                heroIcon["position_y"] = 0
            end
        end

        -- Update position of bosses on minimap
        for unitId, bossIcon in pairs(bossIcons) do
            local unit = Map.Current.FindUnitById(unitId)
            if unit then
                local position = unit:GetPosition()
                if position and
                    position.x >= min_x and position.x <= max_x and
                    position.y >= min_y and position.y <= max_y then
                    -- Can exact position of the boss be seen by player's team?
                    local fullyVisible = (selfTeam == GAME_TEAM_SPECTATOR) or event.unit:CanBeSeenByTeam(self:GetPlayer():GetTeam())

                    if (not fullyVisible) and unit.GetSpawnPosition and unit:GetSpawnPosition() then
                        position = unit:GetSpawnPosition()
                    end
                    bossIcon["visible"] = true
                    bossIcon["position_x"] = (position.x - min_x) / size_x
                    bossIcon["position_y"] = (position.y - min_y) / size_y
                else -- not position
                    bossIcon["visible"] = false
                    bossIcon["position_x"] = 0
                    bossIcon["position_y"] = 0
                end
            else -- not unit
                bossIcon["visible"] = false
                bossIcon["position_x"] = 0
                bossIcon["position_y"] = 0
            end
        end
    end)
end

------------------------------------------------------------------------------------------------------------------------

local heroIcons = {}

function Minimap:OnHeroCreate(event)
    local hero = event.unit
    local heroId = hero:GetUnitId()

    local heroTeam = hero:GetTeam()
    local selfTeam = self:GetPlayer():GetTeam()

    heroIcons[heroId] = Gui.CreateElement("Image", {
        id = "minimap_icon_hero_" .. heroId,
        class = "minimap_icon_hero",
        color = hero:GetPlayerColor(),
        hero_id = heroId,
        hero_name = hero:GetUnitName(),
        hero_level = hero:GetLevel(),
        visible = false,
        team_enemy = (selfTeam == GAME_TEAM_SPECTATOR) and (heroTeam == GAME_TEAM_1) or (heroTeam == selfTeam) -- x ? y : z
    }, self.minimap_panel)
end

function Minimap:OnHeroDestroy(event)
    local heroId = event.unit:GetUnitId()
    local icon = heroIcons[heroId]
    if icon then
        Table.Remove(heroIcons, heroId)
        Gui.Destroy(icon)
    end
end

------------------------------------------------------------------------------------------------------------------------

local bossIcons = {}

function Minimap:OnBossCreate(event)
    local boss = event.unit
    local bossId = boss:GetUnitId()
    bossIcons[bossId] = Gui.CreateElement("Image", {
        id = "minimap_icon_boss_" .. bossId,
        class = "minimap_icon_boss",
        boss_id = bossId,
        boss_name = boss:GetUnitName(),
        boss_level = boss:GetLevel(),
        visible = false
    }, self.minimap_panel)
end

function Minimap:OnBossDestroy(event)
    local bossId = event.unit:GetUnitId()
    local icon = heroIcons[bossId]
    if icon then
        Table.Remove(heroIcons, bossId)
        Gui.Destroy(icon)
    end
end

------------------------------------------------------------------------------------------------------------------------
function Minimap:OnMinimapClick(event)
    if event.MouseButton == MOUSE_BUTTON_LEFT then
        --TODO move view
    end
    if event.MouseButton == MOUSE_BUTTON_RIGHT then
        --TODO move unit
    end
end

------------------------------------------------------------------------------------------------------------------------
function Minimap:OnMinimapPing(event)
    if event.MouseButton == MOUSE_BUTTON_LEFT then
        --TODO normal ping
    end
    if event.MouseButton == MOUSE_BUTTON_RIGHT then
        --TODO deny ping
    end
end
