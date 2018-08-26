item_eye_of_skadi = base(Item)

------------------------------------------------------------------------------------------------------------------------

function item_eye_of_skadi:GetPassiveModifier()
    return "modifier_eye_of_skadi"
end

------------------------------------------------------------------------------------------------------------------------

function item_eye_of_skadi:OnAttackLanded(event)
    event.target:AddNewModifier(self:GetOwner(), self, "modifier_eye_of_skadi_slow", {
        slow = self:GetValue("slow"),
        duration = self:GetValue("slow_duration") * event.target:GetStatusResistance()
    })
end

------------------------------------------------------------------------------------------------------------------------

modifier_eye_of_skadi = base(Modifier) 

------------------------------------------------------------------------------------------------------------------------

function modifier_eye_of_skadi:GetBonusStrength()
    return self:GetValue("bonus_attribute_all")
end

function modifier_eye_of_skadi:GetBonusAgility()
    return self:GetValue("bonus_attribute_all")
end

function modifier_eye_of_skadi:GetBonusIntelligence()
    return self:GetValue("bonus_attribute_all")
end

function modifier_eye_of_skadi:GetBonusCharisma()
    return self:GetValue("bonus_attribute_all")
end

------------------------------------------------------------------------------------------------------------------------

function modifier_eye_of_skadi:GetProjectileParticle()
    return "projectile/eye_of_skadi"
end

------------------------------------------------------------------------------------------------------------------------

modifier_eye_of_skadi_slow = base(Modifier)

------------------------------------------------------------------------------------------------------------------------

function modifier_eye_of_skadi_slow:GetPercentageBonusMovementSpeed()
    return self.slow
end
