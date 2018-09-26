local Minimap = Gui("Minimap")

function Minimap:Init()
    -- Hero
    Events:RegisterListener("Hero.Create", self.OnHeroCreate)
    Events:RegisterListener("Bero.Destroy", self.OnHeroDestroy)
    -- Boss
    Events:RegisterListener("Boss.Create", self.OnBossCreate)
    Events:RegisterListener("Boss.Destroy", self.OnBossDestroy)

    -- Store reference to minimap panel
    self.minimap_panel = Gui.GetElementById("Minimap")
    -- Make sure there are limits (this is shorter way than if conditions)
    self.minimap_panel["Min_X"] = self.minimap_panel["Min_X"] or 0
    self.minimap_panel["Min_Y"] = self.minimap_panel["Min_Y"] or 0
    self.minimap_panel["Max_X"] = self.minimap_panel["Max_X"] or 0
    self.minimap_panel["Max_Y"] = self.minimap_panel["Max_Y"] or 0

    self.heroIcons = {}
    self.bossIcons = {}

    -- Position update Timer
    Timers.CreateTimer(0.25, function()
        local min_x = self.minimap_panel.min_x
        local min_y = self.minimap_panel.min_y
        local max_x = self.minimap_panel.max_x
        local max_y = self.minimap_panel.max_y
        local size_x = max_x - min_x
        local size_y = max_y - min_y

        -- Update position of heroes on minimap
        for unitId, heroIcon in pairs(self.heroIcons) do
            local unit = Map.Current.FindUnitById(unitId)
            if unit then
                local position = unit:GetPosition()
                if position and
                    position.x >= min_x and position.x <= max_x and
                    position.y >= min_y and position.y <= max_y then
                    heroIcon["Visible"] = true
                    heroIcon["Position_X"] = (position.x - min_x) / size_x
                    heroIcon["Position_Y"] = (position.y - min_y) / size_y
                else -- not position
                    heroIcon["Visible"] = false
                    heroIcon["Position_X"] = 0
                    heroIcon["Position_Y"] = 0
                end
            else -- not unit
                heroIcon["Visible"] = false
                heroIcon["Position_X"] = 0
                heroIcon["Position_Y"] = 0
            end
        end

        -- Update position of bosses on minimap
        for unitId, bossIcon in pairs(self.bossIcons) do
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
                    bossIcon["Visible"] = true
                    bossIcon["Position_X"] = (position.x - min_x) / size_x
                    bossIcon["Position_Y"] = (position.y - min_y) / size_y
                else -- not position
                    bossIcon["Visible"] = false
                    bossIcon["Position_X"] = 0
                    bossIcon["Position_Y"] = 0
                end
            else -- not unit
                bossIcon["Visible"] = false
                bossIcon["Position_X"] = 0
                bossIcon["Position_Y"] = 0
            end
        end
    end)
end

------------------------------------------------------------------------------------------------------------------------

function Minimap:OnHeroCreate(event)
    local hero = event.unit
    local heroId = hero:GetUnitId()

    local heroTeam = hero:GetTeam()
    local selfTeam = self:GetPlayer():GetTeam()

    self.heroIcons[heroId] = Gui.CreateElement("Image", {
        id = "Minimap_Icon_Hero_" .. heroId,
        class = "Minimap_Icon_Hero",
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
    local icon = self.heroIcons[heroId]
    if icon then
        Table.Remove(self.heroIcons, heroId)
        Gui.Destroy(icon)
    end
end

------------------------------------------------------------------------------------------------------------------------

function Minimap:OnBossCreate(event)
    local boss = event.unit
    local bossId = boss:GetUnitId()
    self.bossIcons[bossId] = Gui.CreateElement("Image", {
        id = "Ninimap_Icon_Boss_" .. bossId,
        class = "Minimap_Icon_Boss",
        boss_id = bossId,
        boss_name = boss:GetUnitName(),
        boss_level = boss:GetLevel(),
        visible = false
    }, self.minimap_panel)
end

function Minimap:OnBossDestroy(event)
    local bossId = event.unit:GetUnitId()
    local icon = self.bossIcons[bossId]
    if icon then
        Table.Remove(self.bossIcons, bossId)
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
